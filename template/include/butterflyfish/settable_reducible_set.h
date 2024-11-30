#ifndef _BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_H_
#define _BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "settable_set_$t$.h"
#include "reducible_set_$t$.h"

$d$

#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_SET_$T$_ERROR_VALUE_NOT_FOUND

struct butterflyfish_settable_reducible_set_$t$ {
    int (*const as_settable_set)(
            struct butterflyfish_settable_reducible_set_$t$ *object,
            struct butterflyfish_settable_set_$t$ **out);

    int (*const as_reducible_set)(
            struct butterflyfish_settable_reducible_set_$t$ *object,
            struct butterflyfish_reducible_set_$t$ **out);
};

/**
 * @brief Return settable reducible set as a stream.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_stream(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return settable reducible set as a collection.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_collection(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Return settable reducible set as a settable.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_settable(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        struct butterflyfish_settable_$t$ **out);

/**
 * @brief Return settable reducible set as a set.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_set(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_set_$t$ **out);

/**
 * @brief Return settable reducible set as a removable.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_removable(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        struct butterflyfish_removable_$t$ **out);

/**
 * @brief Return settable reducible set as a settable set.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_settable_set(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        struct butterflyfish_settable_set_$t$ **out);

/**
 * @brief Return settable reducible set as a reducible set.
 * @param [in] object settable incremental set instance.
 * @param [out] out receive reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_as_reducible_set(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        struct butterflyfish_reducible_set_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_reducible_set_$t$_count(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of the settable reducible set.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY if set
 * is empty.
 */
int butterflyfish_settable_reducible_set_$t$_first(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of the settable reducible set.
 * @param [in] object settable reducible set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_SET_IS_EMPTY if set
 * is empty.
 */
int butterflyfish_settable_reducible_set_$t$_last(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object settable reducible set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_settable_reducible_set_$t$_next(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object settable reducible set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_END_OF_SEQUENCE if
 * there is no previous item.
 */
int butterflyfish_settable_reducible_set_$t$_prev(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Check if settable reducible set contains the given value.
 * @param [in] object settable reducible set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_settable_reducible_set_$t$_contains(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$value,
        bool *out);

/**
 * @brief Check if settable reducible set contains all the given values.
 * @param [in] object settable reducible set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_settable_reducible_set_$t$_contains_all(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object settable reducible set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_settable_reducible_set_$t$_get(
        const struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$value,
        const $v$*out);

/**
 * @brief Set value for item.
 * @param [in] object settable reducible set instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
 * if value is already present in the set.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_settable_reducible_set_$t$_set_item(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Set value for looked up item.
 * @param [in] object settable reducible set instance.
 * @param [in] item to lookup.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * item is not in the set.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_ALREADY_EXISTS
 * if value is already present in the set.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_INVALID
 * if value is invalid.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then the lookup item is set to it.
 */
int butterflyfish_settable_reducible_set_$t$_set(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$item,
        const $v$value);

/**
 * @brief Remove item.
 * @param [in] object settable reducible set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_settable_reducible_set_$t$_remove_item(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$item);

/**
 * @brief Remove all items.
 * @param [in] object settable reducible set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_settable_reducible_set_$t$_remove_all_items(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Remove value from the settable reducible set.
 * @param [in] object settable reducible set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_settable_reducible_set_$t$_remove(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const $v$value);

/**
 * @brief Remove values from the settable reducible set.
 * @param [in] object settable reducible set instance.
 * @param [in] other stream whose values will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the streamed values in the set.
 */
int butterflyfish_settable_reducible_set_$t$_remove_all(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

/**
 * @brief Retain all the values present in both.
 * @param [in] object settable reducible set instance.
 * @param [in] other stream whose values, if present in set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_settable_reducible_set_$t$_retain_all(
        struct butterflyfish_settable_reducible_set_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_SETTABLE_REDUCIBLE_SET_$T$_H_ */
