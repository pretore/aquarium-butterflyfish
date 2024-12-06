#ifndef _BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_H_
#define _BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "map_$t$_entry.h"
#include "mutable_map_$t$.h"
#include "ordered_settable_incremental_map_$t$.h"
#include "ordered_settable_reducible_map_$t$.h"

struct butterflyfish_stream_$mkt$;
struct butterflyfish_stream_$mvt$;
struct butterflyfish_ordered_mutable_set_$mkt$;
struct butterflyfish_ordered_settable_reducible_list_$mvt$;

#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_NOT_FOUND \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_ENTRY_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS
#define BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_INVALID \
    BUTTERFLYFISH_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_INVALID

struct butterflyfish_ordered_mutable_map_$t$ {
    int (*const as_ordered_settable_incremental_map)(
            struct butterflyfish_ordered_mutable_map_$t$ *object,
            struct butterflyfish_ordered_settable_incremental_map_$t$ **out);

    int (*const as_ordered_settable_reducible_map)(
            struct butterflyfish_ordered_mutable_map_$t$ *object,
            struct butterflyfish_ordered_settable_reducible_map_$t$ **out);

    int (*const as_mutable_map)(
            struct butterflyfish_ordered_mutable_map_$t$ *object,
            struct butterflyfish_mutable_map_$t$ **out);

    int (*const keys)(
            struct butterflyfish_ordered_mutable_map_$t$ *object,
            struct butterflyfish_ordered_mutable_set_$mkt$ **out);

    int (*const values)(
            struct butterflyfish_ordered_mutable_map_$t$ *object,
            struct butterflyfish_ordered_settable_reducible_list_$mvt$ **out);
};

/**
 * @brief Return ordered mutable map as a stream.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_stream(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return ordered mutable map as a collection.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_collection(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return ordered mutable map as a set.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_set(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Return ordered mutable map as a map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_map(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_map_$t$ **out);

/**
 * @brief Return ordered mutable map as a settable.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_settable(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_settable_$t$ **out);

/**
 * @brief Return ordered mutable map as an addable.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_addable(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_addable_$t$ **out);

/**
 * @brief Return ordered mutable map as a removable.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_removable(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_removable_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_ordered_$t$ **out);

/**
 * @brief Return ordered mutable map as an insertable.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_insertable(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_insertable_$t$ **out);

/**
 * @brief Return ordered mutable map as a settable map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive settable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_settable_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_settable_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an incremental map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_incremental_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_incremental_map_$t$ **out);

/**
 * @brief Return ordered mutable map as a reducible map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_reducible_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_reducible_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_map(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_ordered_map_$t$ **out);

/**
 * @brief Return ordered mutable map as a settable incremental map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive settable incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_settable_incremental_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_settable_incremental_map_$t$ **out);

/**
 * @brief Return ordered mutable map as a settable reducible map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive settable reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_settable_reducible_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_settable_reducible_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered incremental map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_incremental_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_incremental_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered settable map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered settable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_settable_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered reducible map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_reducible_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_reducible_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered settable incremental map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered settable incremental map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_incremental_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_settable_incremental_map_$t$ **out);

/**
 * @brief Return ordered mutable map as an ordered settable reducible map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive ordered settable reducible map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_ordered_settable_reducible_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_settable_reducible_map_$t$ **out);

/**
 * @brief Return ordered mutable map as a mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive mutable map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_as_mutable_map(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_mutable_map_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_count(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY if map is
 * empty.
 */
int butterflyfish_ordered_mutable_map_$t$_first(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MAP_IS_EMPTY if map is
 * empty.
 */
int butterflyfish_ordered_mutable_map_$t$_last(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered mutable map instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_ordered_mutable_map_$t$_next(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered mutable map instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_ordered_mutable_map_$t$_prev(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if ordered mutable map contains the given entry.
 * @param [in] object ordered mutable map instance.
 * @param [in] entry to check if entry is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL if entry
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$entry,
        bool *out);

/**
 * @brief Check if ordered mutable map contains the given key.
 * @param [in] object ordered mutable map instance.
 * @param [in] key to check if key is present.
 * @param [out] out receive true if key is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains_key(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        bool *out);

/**
 * @brief Check if ordered mutable map contains the given value.
 * @param [in] object ordered mutable map instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains_value(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mvv$value,
        bool *out);

/**
 * @brief Check if ordered mutable map contains all the given entries.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered mutable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains_all(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Check if ordered mutable map contains all the given keys.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered mutable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains_all_keys(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$mkt$ *other,
        bool *out);

/**
 * @brief Check if ordered mutable map contains all the given values.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered mutable map.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_contains_all_values(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$mvt$ *other,
        bool *out);

/**
 * @brief Retrieve matching entry.
 * @param [in] object ordered mutable map instance.
 * @param [in] entry to find.
 * @param [out] out receive the matching entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL if entry
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_NOT_FOUND if
 * entry is not in the map instance.
 * @throws
 * BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_get(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$entry,
        const $v$*out);

/**
 * @brief Retrieve associated value for key.
 * @param [in] object settable incremental map instance.
 * @param [in] key to find.
 * @param [out] out receive the associated value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND if key
 * is not in the map instance.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_ordered_mutable_map_$t$_get_value(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        const $mvv$*out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object ordered mutable map instance.
 * @param [in] key to find.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND if key
 * is not in the map instance.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_ordered_mutable_map_$t$_get_entry(
        const struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        const $v$*out);

/**
 * @brief Set associated value for key.
 * @param [in] object ordered mutable map instance.
 * @param [in] key for whose associated value will be set.
 * @param [in] value for value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND if key
 * is not in the map instance.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the value.
 * @note <b>value</b> is copied and then the associated value is set to it.
 */
int butterflyfish_ordered_mutable_map_$t$_set_value(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        const $mvv$value);

/**
 * @brief Replace key.
 * @param [in] object ordered mutable map instance.
 * @param [in] key for whose value to be set.
 * @param [in] value for key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND if key
 * is not in the map instance.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if
 * key is already present in the map.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the key.
 * @note <b>value</b> is copied and then the key is set to it.
 */
int butterflyfish_ordered_mutable_map_$t$_set_key(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        const $mkv$value);

/**
 * @brief Replace entry.
 * @param [in] object ordered mutable map instance.
 * @param [in] entry to be changed.
 * @param [in] value to set entry to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL if entry
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if
 * key is already present in the map.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to set the entry.
 * @note <b>value</b> is copied and then entry is set to it.
 */
int butterflyfish_ordered_mutable_map_$t$_set_entry(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$entry,
        const $v$value);

/**
 * @brief Add entry.
 * @param [in] object ordered mutable map instance.
 * @param [in] entry to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL if entry
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if
 * key is already present in the map.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_INVALID if
 * entry is invalid.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value.
 * @note <b>value</b> is copied.
 */
int butterflyfish_ordered_mutable_map_$t$_add(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$entry);

/**
 * @brief Add all the values.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values.
 * @note streamed <b>values</b> are copied.
 */
int butterflyfish_ordered_mutable_map_$t$_add_all(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Add value for key.
 * @param [in] object ordered mutable map instance.
 * @param [in] key used for finding the associated value.
 * @param [in] value to add.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_ALREADY_EXISTS if
 * key is already present in the map.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied.
 */
int butterflyfish_ordered_mutable_map_$t$_add_value(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key,
        const $mvv$value);

/**
 * @brief Insert value into the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is  <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_ALREADY_EXISTS
 * if value is already present.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the insertable.
 * @note <b>value</b> is copied and then placed into the insertable.
 */
int butterflyfish_ordered_mutable_map_$t$_insert(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Insert all the values into to the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the insertable.
 * @note streamed <b>values</b> are copied and then placed into the insertable.
 */
int butterflyfish_ordered_mutable_map_$t$_insert_all(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$item,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Remove key from the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [in] key to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_KEY_NOT_FOUND if key
 * is not in the map instance.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_remove(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $mkv$key);

/**
 * @brief Remove keys from the ordered mutable map.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose keys will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the streamed keys in the map.
 */
int butterflyfish_ordered_mutable_map_$t$_remove_all(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$mkt$ *other);

/**
 * @brief Retain all the keys present in both.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream whose keys, if present in map too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the entry.
 */
int butterflyfish_ordered_mutable_map_$t$_retain_all(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$mkt$ *other);

/**
 * @brief Remove entry.
 * @param [in] object ordered mutable map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_ENTRY_IS_NULL if entry
 * is <i>NULL</i>.
 * @note <b>entry</b> is invalidated when removed.
 */
int butterflyfish_ordered_mutable_map_$t$_remove_entry(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const $v$entry);

/**
 * @brief Remove all entries.
 * @param [in] object ordered mutable map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @note streamed entries within <b>other</b> is invalidated when removed.
 */
int butterflyfish_ordered_mutable_map_$t$_remove_all_entries(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Retrieve set view of keys.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive set view of keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_keys(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_mutable_set_$mkt$ **out);

/**
 * @brief Retrieve list view of values.
 * @param [in] object ordered mutable map instance.
 * @param [out] out receive list view of values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_mutable_map_$t$_values(
        struct butterflyfish_ordered_mutable_map_$t$ *object,
        struct butterflyfish_ordered_settable_reducible_list_$mvt$ **out);

#endif /* _BUTTERFLYFISH_ORDERED_MUTABLE_MAP_$T$_H_ */
