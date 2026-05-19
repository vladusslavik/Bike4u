#pragma once

#include "main.h"


#define EXTI_PIN(line)		(EXTI->PR & (1U << (line)))
#define EXTI_CLEAR(line)	(EXTI->PR = (1U << (line)))

#define EXTI_LEFT_BUT		5
#define EXTI_MIDL_BUT		4
#define EXTI_RGHT_BUT		3
