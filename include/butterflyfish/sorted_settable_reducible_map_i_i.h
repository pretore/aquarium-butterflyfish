#ifndef _BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_H_
#define _BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "sorted_settable_map_i_i.h"
#include "sorted_reducible_map_i_i.h"
#include "settable_reducible_map_i_i.h"

struct sea_turtle_integer;
struct butterflyfish_sorted_settable_reducible_set_i;
struct butterflyfish_ordered_settable_reducible_list_i;

#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_SORTED_SETTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS

struct butterflyfish_sorted_settable_reducible_map_i_i {
    int (*const as_sorted_settable_map)(
            struct butterflyfish_sorted_settable_reducible_map_i_i *object,
            struct butterflyfish_sorted_settable_map_i_i **out);

    int (*const as_settable_reducible_map)(
            struct butterflyfish_sorted_settable_reducible_map_i_i *object,
            struct butterflyfish_settable_reducible_map_i_i **out);

    int (*const as_sorted_reducible_map)(
            struct butterflyfish_sorted_settable_reducible_map_i_i *object,
            struct butterflyfish_sorted_reducible_map_i_i **out);

    int (*const keys)(
            struct butterflyfish_sorted_settable_reducible_map_i_i *object,
            struct butterflyfish_sorted_settable_reducible_set_i **out);

    int (*const values)(
            struct butterflyfish_sorted_settable_reducible_map_i_i *object,
            struct butterflyfish_ordered_settable_reducible_list_i **out);
};

/**
 * @brief Return sorted settable reducible map as a stream.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_stream(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return sorted settable reducible map as a collection.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_collection(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return sorted settable reducible map as a set.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_set(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_set_i_i **out);

/**
 * @brief Return sorted settable reducible map as an sorted.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive sorted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_sorted_i_i **out);

/**
 * @brief Return sorted settable reducible map as a settable.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_settable(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return sorted settable reducible map as a removable.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_removable(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_removable_i_i **out);

/**
 * @brief Return sorted settable reducible map as a map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_map(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i **out);

/**
 * @brief Return sorted settable reducible map as a sorted map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive sorted map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_map(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_sorted_map_i_i **out);

/**
 * @brief Return sorted settable map as a settable map.
 * @param [in] object sorted settable map instance.
 * @param [out] out receive settable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_settable_map_i_i **out);

/**
 * @brief Return sorted settable reducible map as a reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_reducible_map_i_i **out);

/**
 * @brief Return sorted settable reducible map as a sorted reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive sorted reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_settable_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_sorted_settable_map_i_i **out);

/**
 * @brief Return sorted settable reducible map as a settable reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive settable reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_settable_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_settable_reducible_map_i_i **out);

/**
 * @brief Return sorted settable reducible map as a sorted reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive sorted reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_as_sorted_reducible_map(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_sorted_reducible_map_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_count(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the sorted settable reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MAP_IS_EMPTY
 * if map is empty.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_first(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the sorted settable reducible map.
 * @param [in] object map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MAP_IS_EMPTY
 * if map is empty.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_last(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_next(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ITEM_IS_NULL
 * if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_prev(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Check if sorted settable reducible map contains the given entry.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] entry to check if entry is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL if
 * entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        bool *out);

/**
 * @brief Check if sorted settable reducible map contains the given key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains_key(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        bool *out);

/**
 * @brief Check if sorted settable reducible map contains the given value.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains_value(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if sorted settable reducible map contains all the given entries.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains_all(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        bool *out);

/**
 * @brief Check if sorted settable reducible map contains all the given keys.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains_all_keys(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Check if sorted settable reducible map contains all the given values.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_contains_all_values(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] entry to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL
 * if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND
 * if entry is not in the map instance.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_get(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_get_value(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_get_entry(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Set value for key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key for whose associated value will be set.
 * @param [in] value for value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if key is not in the map instance.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the value.
 * @note <b>value</b> is copied and then the associated value is set to it.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_set_value(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key for whose value to be set.
 * @param [in] value for key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if key is not in the map instance.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the key.
 * @note <b>value</b> is copied and then the key is set to it.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_set_key(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace entry.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] entry to be changed.
 * @param [in] value to set entry to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL
 * if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_NULL
 * if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the entry.
 * @note <b>value</b> is copied and then entry is set to it.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_set_entry(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Retrieve entry for key or the next higher key.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key to find or its next higher.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if no key in sorted was equal to or higher than given key.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_ceiling(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve entry for key or the next lower key.
 * @param [in] object sorted map instance.
 * @param [in] key to find or its next lower.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if no key in sorted was equal to or lower than given key.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_floor(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve entry for next higher key.
 * @param [in] object sorted map instance.
 * @param [in] key whose next higher key we are trying to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if no key in sorted is greater.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_higher(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve entry for the next lower key.
 * @param [in] object sorted map instance.
 * @param [in] key whose next lower key we are trying to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if no key in sorted is lower.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_lower(
        const struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Remove key from the sorted settable reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] key to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_IS_NULL
 * if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_KEY_NOT_FOUND
 * if key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_remove(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct sea_turtle_integer *key);

/**
 * @brief Remove keys from the sorted settable reducible map.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream whose keys will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the streamed keys in the map.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_remove_all(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Retain all the keys present in both.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream whose keys, if present in map too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_retain_all(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Remove entry.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_ENTRY_IS_NULL
 * if entry is <i>NULL</i>.
 * @note <b>entry</b> is invalidated when removed.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_remove_entry(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry);

/**
 * @brief Remove all entries.
 * @param [in] object sorted settable reducible map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OTHER_IS_NULL
 * if other is <i>NULL</i>.
 * @note streamed entries within <b>other</b> is invalidated when removed.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_remove_all_entries(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Retrieve reducible set view of keys.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive reducible set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_keys(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_sorted_settable_reducible_set_i **out);

/**
 * @brief Retrieve reducible list view of values.
 * @param [in] object sorted settable reducible map instance.
 * @param [out] out receive reducible list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OBJECT_IS_NULL
 * if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 */
int butterflyfish_sorted_settable_reducible_map_i_i_values(
        struct butterflyfish_sorted_settable_reducible_map_i_i *object,
        struct butterflyfish_ordered_settable_reducible_list_i **out);

#endif /* _BUTTERFLYFISH_SORTED_SETTABLE_REDUCIBLE_MAP_I_I_H_ */
