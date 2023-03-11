#ifndef _BUTTERFLYFISH_MAP_ENTRY_P_P_H_
#define _BUTTERFLYFISH_MAP_ENTRY_P_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct butterflyfish_map_p_p;

#define BUTTERFLYFISH_MAP_ENTRY_P_P_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_P_P_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_P_P_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_P_P_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL

struct butterflyfish_map_entry_p_p;

int butterflyfish_map_entry_p_p_key(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry,
        const void **out);

int butterflyfish_map_entry_p_p_get_value(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry,
        const void **out);

int butterflyfish_map_entry_p_p_set_value(
        struct butterflyfish_map_p_p *object,
        struct butterflyfish_map_entry_p_p *entry,
        const void *value);

#endif /* _BUTTERFLYFISH_MAP_ENTRY_P_P_H_ */
