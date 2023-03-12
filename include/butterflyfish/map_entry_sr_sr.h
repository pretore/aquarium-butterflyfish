#ifndef _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_
#define _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct triggerfish_strong;
struct butterflyfish_map_sr_sr;

#define BUTTERFLYFISH_MAP_ENTRY_SR_SR_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_SR_SR_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_SR_SR_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_SR_SR_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL

struct butterflyfish_map_entry_sr_sr;

int butterflyfish_map_entry_sr_sr_key(
        const struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct triggerfish_strong **out);

int butterflyfish_map_entry_sr_sr_get_value(
        const struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct triggerfish_strong **out);

int butterflyfish_map_entry_sr_sr_set_value(
        struct butterflyfish_map_sr_sr *object,
        struct butterflyfish_map_entry_sr_sr *entry,
        struct triggerfish_strong *value);

#endif /* _BUTTERFLYFISH_MAP_ENTRY_SR_SR_H_ */
