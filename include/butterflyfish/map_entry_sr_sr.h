#ifndef _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_
#define _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct triggerfish_strong;

struct butterflyfish_map_entry_sr_sr {
    struct triggerfish_strong *const key;
    struct triggerfish_strong *const value;
};

#endif /* _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_ */
