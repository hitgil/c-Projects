#ifndef COMMONHEADDER_H
#define COMMONHEADDER_H

#include <iostream>
#include "../inc/bank.h"
#include "../inc/user.h"
#include "../inc/admin.h"

extern void handleAdminActions(Bank &myBank);
extern void handleUserActions(Bank &myBank);

#endif