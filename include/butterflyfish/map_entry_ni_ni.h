#ifndef _BUTTERFLYFISH_MAP_ENTRY_NI_NI_H_
#define _BUTTERFLYFISH_MAP_ENTRY_NI_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct butterflyfish_map_ni_ni;

#define BUTTERFLYFISH_MAP_ENTRY_NI_NI_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_NI_NI_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_NI_NI_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_ENTRY_NI_NI_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL

struct butterflyfish_map_entry_ni_ni;

int butterflyfish_map_entry_ni_ni_key(
        const struct butterflyfish_map_ni_ni *object,
        const struct butterflyfish_map_entry_ni_ni *entry,
        const uintmax_t *out);

int butterflyfish_map_entry_ni_ni_get_value(
        const struct butterflyfish_map_ni_ni *object,
        const struct butterflyfish_map_entry_ni_ni *entry,
        const uintmax_t *out);

int butterflyfish_map_entry_ni_ni_set_value(
        struct butterflyfish_map_ni_ni *object,
        struct butterflyfish_map_entry_ni_ni *entry,
        uintmax_t value);

#endif /* _BUTTERFLYFISH_MAP_ENTRY_NI_NI_H_ */
