#ifndef _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_H_
#define _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_settable_map_i_i.h"
#include "ordered_incremental_map_i_i.h"
#include "settable_incremental_map_i_i.h"

struct sea_turtle_integer;
struct butterflyfish_ordered_settable_incremental_set_i;
struct butterflyfish_ordered_settable_list_i;

#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_ENTRY_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_SETTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS

struct butterflyfish_ordered_settable_incremental_map_i_i {
    int (*const as_ordered_settable_map)(
            struct butterflyfish_ordered_settable_incremental_map_i_i *object,
            struct butterflyfish_ordered_settable_map_i_i **out);

    int (*const as_ordered_incremental_map)(
            struct butterflyfish_ordered_settable_incremental_map_i_i *object,
            struct butterflyfish_ordered_incremental_map_i_i **out);

    int (*const as_settable_incremental_map)(
            struct butterflyfish_ordered_settable_incremental_map_i_i *object,
            struct butterflyfish_settable_incremental_map_i_i **out);

    int (*const keys)(
            struct butterflyfish_ordered_settable_incremental_map_i_i *object,
            struct butterflyfish_ordered_settable_incremental_set_i **out);

    int (*const values)(
            struct butterflyfish_ordered_settable_incremental_map_i_i *object,
            struct butterflyfish_ordered_settable_list_i **out);
};

/**
 * @brief Return ordered settable incremental map as a stream.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_stream(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return ordered settable incremental map as a collection.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_collection(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return ordered settable incremental map as a set.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_set(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_set_i_i **out);

/**
 * @brief Return ordered settable incremental map as a ordered.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_ordered(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_ordered_i_i **out);

/**
 * @brief Return ordered settable incremental map as an addable.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_addable(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_addable_i_i **out);

/**
 * @brief Return ordered settable incremental map as a settable.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_settable(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return ordered settable incremental map as a map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_map(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as a ordered map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive ordered map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_ordered_map(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_ordered_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as a settable map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive settable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_settable_map(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_settable_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as an incremental map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_incremental_map(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_incremental_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as an ordered settable map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive ordered settable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_as_ordered_settable_map(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_ordered_settable_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as an ordered incremental map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive ordered incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int
butterflyfish_ordered_settable_incremental_map_i_i_as_ordered_incremental_map(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_ordered_incremental_map_i_i **out);

/**
 * @brief Return ordered settable incremental map as a settable incremental map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive settable incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 */
int
butterflyfish_ordered_settable_incremental_map_i_i_as_settable_incremental_map(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        struct butterflyfish_settable_incremental_map_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_count(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered settable incremental map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MAP_IS_EMPTY if
 * map is empty.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_first(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the ordered settable incremental map.
 * @param [in] object ordered settable incremental map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MAP_IS_EMPTY if
 * map is empty.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_last(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_next(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_prev(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Check if ordered settable incremental map contains the given entry.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL if
 * entry is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        bool *out);

/**
 * @brief Check if ordered settable incremental map contains the given key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if
 * key is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains_key(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        bool *out);

/**
 * @brief Check if ordered settable incremental map contains the given value.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains_value(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if ordered settable incremental map contains all the given
 * entries.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL
 * if out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains_all(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        bool *out);

/**
 * @brief Check if ordered settable incremental map contains all the given keys.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if out
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains_all_keys(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Check if ordered settable incremental map contains all the given
 * values.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_contains_all_values(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] value to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL if
 * entry is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_NOT_FOUND if
 * entry is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_get(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve value for key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if
 * key is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND if
 * key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_get_value(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if
 * key is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND if
 * key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_get_entry(
        const struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Set value for key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key for whose associated value will be set.
 * @param [in] value for value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if
 * key is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND if
 * key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the value.
 * @note <b>value</b> is copied and then the associated value is set to it.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_set_value(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key for whose value to be set.
 * @param [in] value for key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if
 * key is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND if
 * key is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the key.
 * @note <b>value</b> is copied and then the key is set to it.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_set_key(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace entry.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] entry to be changed.
 * @param [in] value to set entry to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL if
 * entry is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the entry.
 * @note <b>value</b> is copied and then entry is set to it.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_set_entry(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Add entry.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] entry to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL if
 * entry is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_INVALID
 * if entry is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value.
 * @note <b>value</b> is copied.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_add(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_map_i_i_entry *entry);

/**
 * @brief Add all the values.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values.
 * @note streamed <b>values</b> are copied.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_add_all(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Add value for key.
 * @param [in] object ordered settable incremental map instance.
 * @param [in] key used for finding the associated value.
 * @param [in] value to add.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL if key
 * is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
 * if key is already present in the map.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied.
 */
int butterflyfish_ordered_settable_incremental_map_i_i_add_value(
        struct butterflyfish_ordered_settable_incremental_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

#endif /* _BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_MAP_I_I_H_ */
