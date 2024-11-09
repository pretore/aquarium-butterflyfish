#ifndef _BUTTERFLYFISH_MAP_I_I_H_
#define _BUTTERFLYFISH_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "set_i_i.h"

struct sea_turtle_integer;
struct butterflyfish_stream_i;
struct butterflyfish_set_i;
struct butterflyfish_list_i;

#define BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_SET_I_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_map_i_i {
    int (*const as_set)(
            const struct butterflyfish_map_i_i *object,
            const struct butterflyfish_set_i_i **out);

    int (*const get_value)(
            const struct butterflyfish_map_i_i *object,
            const struct sea_turtle_integer *key,
            const struct sea_turtle_integer **value);

    int (*const get_entry)(
            const struct butterflyfish_map_i_i *object,
            const struct sea_turtle_integer *key,
            const struct butterflyfish_map_i_i_entry **value);

    int (*const contains_key)(
            const struct butterflyfish_map_i_i *object,
            const struct sea_turtle_integer *key,
            bool *out);

    int (*const contains_value)(
            const struct butterflyfish_map_i_i *object,
            const struct sea_turtle_integer *value,
            bool *out);

    int (*const contains_all_keys)(
            const struct butterflyfish_map_i_i *object,
            const struct butterflyfish_stream_i *other,
            bool *out);

    int (*const contains_all_values)(
            const struct butterflyfish_map_i_i *object,
            const struct butterflyfish_stream_i *other,
            bool *out);

    int (*const keys)(
            const struct butterflyfish_map_i_i *object,
            const struct butterflyfish_set_i **out);

    int (*const values)(
            const struct butterflyfish_map_i_i *object,
            const struct butterflyfish_list_i **out);
};

/**
 * @brief Return map as a stream.
 * @param [in] object map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_as_stream(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return map as a collection.
 * @param [in] object map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_as_collection(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return map as a set.
 * @param [in] object map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_as_set(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_set_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_count(
        const struct butterflyfish_map_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the map.
 * @param [in] object map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_i_i_first(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the map.
 * @param [in] object map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_i_i_last(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_map_i_i_next(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE if there is no previous
 * item.
 */
int butterflyfish_map_i_i_prev(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Check if map contains the given entry.
 * @param [in] object map instance.
 * @param [in] entry to check if entry is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        bool *out);

/**
 * @brief Check if map contains the given key.
 * @param [in] object map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains_key(
        const struct butterflyfish_map_i_i *object,
        const struct sea_turtle_integer *key,
        bool *out);

/**
 * @brief Check if map contains the given value.
 * @param [in] object map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains_value(
        const struct butterflyfish_map_i_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if map contains all the given entries.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains_all(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        bool *out);

/**
 * @brief Check if map contains all the given keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains_all_keys(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Check if map contains all the given values.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_contains_all_values(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object map instance.
 * @param [in] entry to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_NOT_FOUND if entry is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_i_i_get(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the value.
 */
int butterflyfish_map_i_i_get_value(
        const struct butterflyfish_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the value.
 */
int butterflyfish_map_i_i_get_entry(
        const struct butterflyfish_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve set view of keys.
 * @param [in] object map instance.
 * @param [out] out receive set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_keys(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_set_i **out);

/**
 * @brief Retrieve list view of values.
 * @param [in] object map instance.
 * @param [out] out receive list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_i_i_values(
        const struct butterflyfish_map_i_i *object,
        const struct butterflyfish_list_i **out);

#endif /* _BUTTERFLYFISH_MAP_I_I_H_ */
