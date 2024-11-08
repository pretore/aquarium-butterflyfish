#ifndef _BUTTERFLYFISH_SETTABLE_MAP_I_I_H_
#define _BUTTERFLYFISH_SETTABLE_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "map_i_i.h"
#include "settable_i_i.h"

struct sea_turtle_integer;
struct butterflyfish_settable_set_i;
struct butterflyfish_settable_list_i;

#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_MAP_I_I_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_MAP_I_I_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_MAP_I_I_ERROR_ENTRY_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS

struct butterflyfish_settable_map_i_i {
    int (*const as_map)(
            const struct butterflyfish_settable_map_i_i *object,
            const struct butterflyfish_map_i_i **out);

    int (*const as_settable) (
            struct butterflyfish_settable_map_i_i *object,
            struct butterflyfish_settable_i_i **out);

    int (*const set_value)(
            struct butterflyfish_settable_map_i_i *object,
            const struct sea_turtle_integer *key,
            const struct sea_turtle_integer *value);

    int (*const set_key)(
            struct butterflyfish_settable_map_i_i *object,
            const struct sea_turtle_integer *key,
            const struct sea_turtle_integer *value);

    int (*const set_entry)(
            struct butterflyfish_settable_map_i_i *object,
            const struct butterflyfish_map_i_i_entry *entry,
            const struct butterflyfish_map_i_i_entry *value);

    int (*const keys)(
            struct butterflyfish_settable_map_i_i *object,
            struct butterflyfish_settable_set_i **out);

    int (*const values)(
            struct butterflyfish_settable_map_i_i *object,
            struct butterflyfish_settable_list_i **out);
};

/**
 * @brief Return settable map as a stream.
 * @param [in] object settable map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_as_stream(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return settable map as a collection.
 * @param [in] object settable map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_as_collection(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return settable map as a set.
 * @param [in] object settable map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_as_set(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_set_i_i **out);

/**
 * @brief Return settable map as a map.
 * @param [in] object settable map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_as_map(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i **out);

/**
 * @brief Return settable map as a settable.
 * @param [in] object settable map instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_as_settable(
        struct butterflyfish_settable_map_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_count(
        const struct butterflyfish_settable_map_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the settable map.
 * @param [in] object settable map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_settable_map_i_i_first(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the settable map.
 * @param [in] object settable map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_settable_map_i_i_last(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object settable map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE if there is
 * no next item.
 */
int butterflyfish_settable_map_i_i_next(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object settable map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE if there is
 * no previous item.
 */
int butterflyfish_settable_map_i_i_prev(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Check if settable map contains the given entry.
 * @param [in] object settable map instance.
 * @param [in] entry to check if entry is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        bool *out);

/**
 * @brief Check if settable map contains the given key.
 * @param [in] object settable map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains_key(
        const struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *key,
        bool *out);

/**
 * @brief Check if settable map contains the given value.
 * @param [in] object settable map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains_value(
        const struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if settable map contains all the given entries.
 * @param [in] object settable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * settable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains_all(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        bool *out);

/**
 * @brief Check if settable map contains all the given keys.
 * @param [in] object settable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * settable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains_all_keys(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Check if settable map contains all the given values.
 * @param [in] object settable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * settable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_contains_all_values(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object settable map instance.
 * @param [in] value to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND if entry is
 * not in the map instance.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_settable_map_i_i_get(
        const struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object settable map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * in the map instance.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_settable_map_i_i_get_value(
        const struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object settable map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * in the map instance.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_settable_map_i_i_get_entry(
        const struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Set value for key.
 * @param [in] object settable map instance.
 * @param [in] key for whose associated value will be set.
 * @param [in] value for value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * in the map instance.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to set the value.
 * @note <b>value</b> is copied and then the associated value is set to it.
 */
int butterflyfish_settable_map_i_i_set_value(
        struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace key.
 * @param [in] object settable map instance.
 * @param [in] key for whose value to be set.
 * @param [in] value for key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * in the map instance.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key
 * is already present in the map.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to set the key.
 * @note <b>value</b> is copied and then the key is set to it.
 */
int butterflyfish_settable_map_i_i_set_key(
        struct butterflyfish_settable_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace entry.
 * @param [in] object settable map instance.
 * @param [in] entry to be changed.
 * @param [in] value to set entry to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key
 * is already present in the map.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to set the entry.
 * @note <b>value</b> is copied and then entry is set to it.
 */
int butterflyfish_settable_map_i_i_set_entry(
        struct butterflyfish_settable_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Retrieve set view of keys.
 * @param [in] object settable map instance.
 * @param [out] out receive set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_keys(
        struct butterflyfish_settable_map_i_i *object,
        struct butterflyfish_settable_set_i **out);

/**
 * @brief Retrieve list view of values.
 * @param [in] object settable map instance.
 * @param [out] out receive list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_map_i_i_values(
        struct butterflyfish_settable_map_i_i *object,
        struct butterflyfish_settable_list_i **out);

#endif /* _BUTTERFLYFISH_SETTABLE_MAP_I_I_H_ */
