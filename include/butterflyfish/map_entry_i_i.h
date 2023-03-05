#ifndef _BUTTERFLYFISH_MAP_ENTRY_I_I_H_
#define _BUTTERFLYFISH_MAP_ENTRY_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct sea_turtle_integer;
struct butterflyfish_map_i_i;

#define BUTTERFLYFISH_MAP_ENTRY_I_I_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_I_I_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_I_I_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_I_I_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL

struct butterflyfish_map_entry_i_i;

int butterflyfish_map_entry_i_i_key(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct sea_turtle_integer **out);

int butterflyfish_map_entry_i_i_get_value(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct sea_turtle_integer **out);

int butterflyfish_map_entry_i_i_set_value(
        struct butterflyfish_map_i_i *object,
        struct butterflyfish_map_entry_i_i *entry,
        const struct sea_turtle_integer *value);

#endif /* _BUTTERFLYFISH_MAP_ENTRY_I_I_H_ */
