/*
 * main.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include "Employee.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <iomanip>

namespace {
void printHierarchy ( const std::map <std::string, std::shared_ptr<employee::Employee>>& hierarchy )
{
	std::for_each( hierarchy.begin(), hierarchy.end(), []( auto& record )
	{
		std::weak_ptr<employee::Employee> pManager{record.second->getManager()};

		std::string managerName{"=None="};

		if(!pManager.expired())
		{
			std::shared_ptr<employee::Employee> spManager{pManager.lock()};
			managerName = spManager->getName();
		}

		std::cout << "[" << std::left << std::setw(8) << record.second->getName() << " - "
				  << std::setw(8) << employee::Employee::roleToString(record.second->getRole())
				  << "] Manager: ( " << std::setw(8) << managerName << " ) Subordinates: ( ";

		std::for_each( record.second->getSubordinates().begin(), record.second->getSubordinates().end(), []( auto& theSubordinate )
		{
			if ( !theSubordinate.second.expired() )
			{
				std::shared_ptr<employee::Employee> spSubordinate{theSubordinate.second.lock()};

				std::cout << std::setw(8) << spSubordinate->getName() << " ";
			}
		});

		std::cout << ")\n";
	});

	std::cout << "\n\n\n";
}
}

int main ( void )
{
	// registro impiegati
	std::map<std::string, std::shared_ptr<employee::Employee> > employeeRegistry;

	// creazione di tutti gli impiegati
	employeeRegistry["alice"  ] = std::make_shared<employee::Employee>("Alice"  , employee::Employee::ERoles::CEO     );
	employeeRegistry["bob"    ] = std::make_shared<employee::Employee>("Bob"    , employee::Employee::ERoles::Manager );
	employeeRegistry["charlie"] = std::make_shared<employee::Employee>("Charlie", employee::Employee::ERoles::Manager );
	employeeRegistry["david"  ] = std::make_shared<employee::Employee>("David"  , employee::Employee::ERoles::Employee);
	employeeRegistry["eva"    ] = std::make_shared<employee::Employee>("Eva"    , employee::Employee::ERoles::Employee);
	employeeRegistry["frank"  ] = std::make_shared<employee::Employee>("Frank"  , employee::Employee::ERoles::Employee);

	//creazione delle relazioni
	employeeRegistry["alice"  ]->addSubordinate( employeeRegistry["bob"    ] );
	employeeRegistry["alice"  ]->addSubordinate( employeeRegistry["charlie"] );

	employeeRegistry["bob"    ]->setManager    ( employeeRegistry["alice"  ] );
	employeeRegistry["bob"    ]->addSubordinate( employeeRegistry["david"  ] );
	employeeRegistry["bob"    ]->addSubordinate( employeeRegistry["eva"    ] );

	employeeRegistry["charlie"]->setManager    ( employeeRegistry["alice"  ] );
	employeeRegistry["charlie"]->addSubordinate( employeeRegistry["frank"  ] );

	employeeRegistry["david"  ]->setManager    ( employeeRegistry["bob"    ] );
	employeeRegistry["eva"    ]->setManager    ( employeeRegistry["bob"    ] );
	employeeRegistry["frank"  ]->setManager    ( employeeRegistry["charlie"] );

	// stampa gerarchia completa
	printHierarchy( employeeRegistry );

	// rimozione di alice e frank
	employeeRegistry.erase("alice");
	employeeRegistry.erase("frank");

	// stampa nuova gerarchia
	printHierarchy( employeeRegistry );

	return 0;
}
