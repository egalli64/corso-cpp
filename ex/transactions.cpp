/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * exercise
 */

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

class Account final
{
  private:
    int id_;
    std::string name_;
    double balance_;

  public:
    Account(const int id, const std::string &name, double balance) : id_(id), name_(name), balance_(balance)
    {
        std::cout << "Ctor: " << name << '\n';
    }

    int id() const
    {
        return id_;
    }

    std::string name() const
    {
        return name_;
    }

    double balance() const
    {
        return balance_;
    }

    void changeBalance(double delta)
    {
        balance_ += delta;
    }
};

std::ostream &operator<<(std::ostream &os, const Account &acc)
{
    return os << acc.id() << ": " << acc.name() << " (" << acc.balance() << ')';
}

class Transaction final
{
  private:
    int id_;
    std::weak_ptr<Account> sender_;
    std::weak_ptr<Account> receiver_;
    double amount_;

  public:
    Transaction(int &id, const std::shared_ptr<Account> &sender, const std::shared_ptr<Account> &receiver,
                double amount)
        : id_(id), sender_(sender), receiver_(receiver), amount_(amount)
    {
    }

    int id() const
    {
        return id_;
    }

    std::shared_ptr<Account> sender() const
    {
        return sender_.lock();
    }

    std::shared_ptr<Account> receiver() const
    {
        return receiver_.lock();
    }

    double amount() const
    {
        return amount_;
    }
};

std::ostream &operator<<(std::ostream &os, const Transaction &t)
{
    return os << t.id() << " From " << *t.sender() << " to " << *t.receiver() << " (" << t.amount() << ')';
}

class Bank
{
  private:
    std::unordered_map<int, std::shared_ptr<Account>> accounts;
    std::vector<std::shared_ptr<Transaction>> transactions;
    std::function<void(std::shared_ptr<Transaction>)> callback_;

  public:
    void account(int id, const std::string &name, double balance)
    {
        accounts[id] = std::make_shared<Account>(id, name, balance);
    }

    void transaction(int id_, int senderId, int receiverId, double amount)
    {
        auto sender = accounts[senderId];
        auto receiver = accounts[receiverId];

        if (!sender || !receiver)
        {
            std::cout << "Invalid transaction\n";
            return;
        }

        if (sender->balance() >= amount)
        {
            sender->changeBalance(-amount);
            receiver->changeBalance(amount);

            auto spt = std::make_shared<Transaction>(id_, sender, receiver, amount);
            transactions.push_back(spt);
            callback_(spt);
        }
        else
        {
            std::cout << "Insufficient funds for the transaction\n";
        }
    }

    void print_account(int accountNumber)
    {
        if (auto spa = accounts[accountNumber]; spa)
        {
            std::cout << "Account " << *spa << '\n';
        }
        else
        {
            std::cout << "Account not found." << '\n';
        }
    }

    void transaction_callback(std::function<void(std::shared_ptr<Transaction>)> callback)
    {
        callback_ = std::move(callback);
    }
};

int main()
{
    Bank bank;
    bank.transaction_callback([](std::shared_ptr<Transaction> spt) {
        std::cout << "Transaction " << *spt << " completed\n";
    });

    bank.account(42, "John Doe", 1000.0);
    bank.account(97, "Jane Smith", 500.0);

    bank.print_account(42);
    bank.print_account(97);

    bank.transaction(1, 42, 97, 200.0);
    bank.transaction(2, 97, 42, 100.0);

    bank.print_account(42);
    bank.print_account(97);
}
