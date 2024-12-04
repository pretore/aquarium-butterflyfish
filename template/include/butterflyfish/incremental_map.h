#ifndef _BUTTERFLYFISH_INCREMENTAL_MAP_$T$_H_
#define _BUTTERFLYFISH_INCREMENTAL_MAP_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "map_$t$_entry.h"
#include "map_$t$.h"
#include "addable_$t$.h"

struct butterflyfish_stream_$mkt$;
struct butterflyfish_stream_$mvt$;
struct butterflyfish_incremental_set_$mkt$;
struct butterflyfish_ordered_list_$mvt$;

#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_MAP_$T$_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_MAP_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_MAP_$T$_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_MAP_$T$_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_MAP_$T$_ERROR_ENTRY_NOT_FOUND
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_MAP_$T$_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_INVALID \
    BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS

struct butterflyfish_incremental_map_$t$ {
    int (*const as_map)(
            const struct butterflyfish_incremental_map_$t$ *object,
            const struct butterflyfish_map_$t$ **out);

    int (*const as_addable)(
            struct butterflyfish_incremental_map_$t$ *object,
            struct butterflyfish_addable_$t$ **out);

    int (*const add_value)(
            struct butterflyfish_incremental_map_$t$ *object,
            const $mkv$key,
            const $mvv$value);

    int (*const keys)(
            struct butterflyfish_incremental_map_$t$ *object,
            struct butterflyfish_incremental_set_$mkt$ **out);

    int (*const values)(
            const struct butterflyfish_incremental_map_$t$ *object,
            const struct butterflyfish_ordered_list_$mvt$ **out);
};

/**
 * @brief Return incremental map as a stream.
 * @param [in] object incremental map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_as_stream(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return incremental map as a collection.
 * @param [in] object incremental map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_as_collection(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return incremental map as a set.
 * @param [in] object incremental map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_as_set(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Return incremental map as an addable.
 * @param [in] object incremental map instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_as_addable(
        struct butterflyfish_incremental_map_$t$ *object,
        struct butterflyfish_addable_$t$ **out);

/**
 * @brief Return incremental map as a map.
 * @param [in] object incremental map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_as_map(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_map_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_count(
        const struct butterflyfish_incremental_map_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the incremental map.
 * @param [in] object incremental map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY if map is
 * empty.
 */
int butterflyfish_incremental_map_$t$_first(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the incremental map.
 * @param [in] object incremental map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY if map is
 * empty.
 */
int butterflyfish_incremental_map_$t$_last(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object incremental map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_incremental_map_$t$_next(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object incremental map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_incremental_map_$t$_prev(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if map contains the given entry.
 * @param [in] object incremental map instance.
 * @param [in] entry to check if present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_i_i_contains(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$entry,
        bool *out);

/**
 * @brief Check if map contains the given key.
 * @param [in] object incremental map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_contains_key(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $mkv$key,
        bool *out);

/**
 * @brief Check if map contains the given value.
 * @param [in] object incremental map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_contains_value(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $mvv$value,
        bool *out);

/**
 * @brief Check if map contains all the given entries.
 * @param [in] object incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_contains_all(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Check if map contains all the given keys.
 * @param [in] object incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_contains_all_keys(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$mkt$ *other,
        bool *out);

/**
 * @brief Check if map contains all the given values.
 * @param [in] object incremental map instance.
 * @param [in] other stream whose values will be checked for presence in map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_contains_all_values(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$mvt$ *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object incremental map instance.
 * @param [in] entry to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_NOT_FOUND if entry
 * is not in the map instance.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_incremental_map_$t$_get(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $v$entry,
        const $v$*out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object incremental map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND if key is
 * not in the map instance.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_incremental_map_$t$_get_value(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $mkv$key,
        const $mvv$*out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object incremental map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND if key is
 * not in the map instance.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_incremental_map_$t$_get_entry(
        const struct butterflyfish_incremental_map_$t$ *object,
        const $mkv$key,
        const $v$*out);

/**
 * @brief Add entry.
 * @param [in] object incremental map instance.
 * @param [in] entry to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if key
 * is already present in the map.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_ENTRY_IS_INVALID if entry is
 * invalid.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value.
 * @note <b>value</b> is copied.
 */
int butterflyfish_incremental_map_$t$_add(
        struct butterflyfish_incremental_map_$t$ *object,
        const $v$entry);

/**
 * @brief Add all the values.
 * @param [in] object incremental map instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values.
 * @note streamed <b>values</b> are copied.
 */
int butterflyfish_incremental_map_$t$_add_all(
        struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Add value for key.
 * @param [in] object incremental map instance.
 * @param [in] key used for finding the associated value.
 * @param [in] value to add.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if key
 * is already present in the map.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID if value
 * is invalid.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied.
 */
int butterflyfish_incremental_map_$t$_add_value(
        struct butterflyfish_incremental_map_$t$ *object,
        const $mkv$key,
        const $mvv$value);

/**
 * @brief Retrieve incremental set view of keys.
 * @param [in] object incremental map instance.
 * @param [out] out receive an incremental set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_keys(
        struct butterflyfish_incremental_map_$t$ *object,
        struct butterflyfish_incremental_set_i **out);

/**
 * @brief Retrieve list view of values.
 * @param [in] object incremental map instance.
 * @param [out] out receive list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_incremental_map_$t$_values(
        const struct butterflyfish_incremental_map_$t$ *object,
        const struct butterflyfish_ordered_list_i **out);

#endif /* _BUTTERFLYFISH_INCREMENTAL_MAP_$T$_H_ */
