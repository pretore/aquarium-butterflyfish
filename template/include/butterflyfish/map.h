#ifndef _BUTTERFLYFISH_MAP_$T$_H_
#define _BUTTERFLYFISH_MAP_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "set_$t$.h"

struct butterflyfish_stream_$mkt$;
struct butterflyfish_stream_$mvt$;
struct butterflyfish_set_$mkt$;
struct butterflyfish_ordered_list_$mvt$;

#define BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_SET_$T$_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_MAP_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MAP_$T$_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND

struct butterflyfish_map_$t$ {
    int (*const as_set)(
            const struct butterflyfish_map_$t$ *object,
            const struct butterflyfish_set_$t$ **out);

    int (*const get_value)(
            const struct butterflyfish_map_$t$ *object,
            const $mkv$key,
            const $mvv$*value);

    int (*const get_entry)(
            const struct butterflyfish_map_$t$ *object,
            const $mkv$key,
            const $v$*out);

    int (*const contains_key)(
            const struct butterflyfish_map_$t$ *object,
            const $mkv$key,
            bool *out);

    int (*const contains_value)(
            const struct butterflyfish_map_$t$ *object,
            const $mvv$value,
            bool *out);

    int (*const contains_all_keys)(
            const struct butterflyfish_map_$t$ *object,
            const struct butterflyfish_stream_$mkt$ *other,
            bool *out);

    int (*const contains_all_values)(
            const struct butterflyfish_map_$t$ *object,
            const struct butterflyfish_stream_$mvt$ *other,
            bool *out);

    int (*const keys)(
            const struct butterflyfish_map_$t$ *object,
            const struct butterflyfish_set_$mkt$ **out);

    int (*const values)(
            const struct butterflyfish_map_$t$ *object,
            const struct butterflyfish_ordered_list_$mvt$ **out);
};

/**
 * @brief Return map as a stream.
 * @param [in] object map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_as_stream(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return map as a collection.
 * @param [in] object map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_as_collection(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return map as a set.
 * @param [in] object map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_as_set(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_count(
        const struct butterflyfish_map_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the map.
 * @param [in] object map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_$t$_first(
        const struct butterflyfish_map_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the map.
 * @param [in] object map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_$t$_last(
        const struct butterflyfish_map_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_map_$t$_next(
        const struct butterflyfish_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_END_OF_SEQUENCE if there is no previous
 * item.
 */
int butterflyfish_map_$t$_prev(
        const struct butterflyfish_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if map contains the given entry.
 * @param [in] object map instance.
 * @param [in] entry to check if entry is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains(
        const struct butterflyfish_map_$t$ *object,
        const $v$entry,
        bool *out);

/**
 * @brief Check if map contains the given key.
 * @param [in] object map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains_key(
        const struct butterflyfish_map_$t$ *object,
        const $mkv$key,
        bool *out);

/**
 * @brief Check if map contains the given value.
 * @param [in] object map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains_value(
        const struct butterflyfish_map_$t$ *object,
        const $mvv$value,
        bool *out);

/**
 * @brief Check if map contains all the given entries.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains_all(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Check if map contains all the given keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains_all_keys(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_stream_$mkt$ *other,
        bool *out);

/**
 * @brief Check if map contains all the given values.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_contains_all_values(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_stream_$mvt$ *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object map instance.
 * @param [in] entry to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_NOT_FOUND if entry is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the entry.
 */
int butterflyfish_map_$t$_get(
        const struct butterflyfish_map_$t$ *object,
        const $v$entry,
        const $v$*out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND if key is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the value.
 */
int butterflyfish_map_$t$_get_value(
        const struct butterflyfish_map_$t$ *object,
        const $mkv$key,
        const $mvv$*out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND if key is not in the
 * map instance.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the value.
 */
int butterflyfish_map_$t$_get_entry(
        const struct butterflyfish_map_$t$ *object,
        const $mkv$key,
        const $v$*out);

/**
 * @brief Retrieve set view of keys.
 * @param [in] object map instance.
 * @param [out] out receive set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_keys(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_set_$mkt$ **out);

/**
 * @brief Retrieve list view of values.
 * @param [in] object map instance.
 * @param [out] out receive list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_$t$_values(
        const struct butterflyfish_map_$t$ *object,
        const struct butterflyfish_ordered_list_$mvt$ **out);

#endif /* _BUTTERFLYFISH_MAP_$T$_H_ */
