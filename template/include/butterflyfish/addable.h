#ifndef _BUTTERFLYFISH_ADDABLE_$T$_H_
#define _BUTTERFLYFISH_ADDABLE_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "collection_$t$.h"

$d$

#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_ADDABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_addable_$t$ {
    int (*const as_collection)(const struct butterflyfish_addable_$t$ *object,
                               const struct butterflyfish_collection_$t$ **out);

    int (*const add)(struct butterflyfish_addable_$t$ *object,
                     const $v$value);

    int (*const add_all)(struct butterflyfish_addable_$t$ *object,
                         const struct butterflyfish_stream_$t$ *other);
};

/**
 * @brief Return addable as a stream.
 * @param [in] object addable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_$t$_as_stream(
        const struct butterflyfish_addable_$t$ *object,
        const struct butterflyfish_stream_$t$ **out);

/**
 * @brief Return addable as a collection.
 * @param [in] object addable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_$t$_as_collection(
        const struct butterflyfish_addable_$t$ *object,
        const struct butterflyfish_collection_$t$ **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_$t$_count(
        const struct butterflyfish_addable_$t$ *object,
        uintmax_t *out);

/**
 * @brief First item of addable.
 * @param [in] object addable instance.
 * @param [out] out receive the first item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_ADDABLE_IS_EMPTY if addable is empty.
 */
int butterflyfish_addable_$t$_first(
        const struct butterflyfish_addable_$t$ *object,
        const $v$*out);

/**
 * @brief Last item of addable.
 * @param [in] object addable instance.
 * @param [out] out receive the last item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_ADDABLE_IS_EMPTY if addable is empty.
 */
int butterflyfish_addable_$t$_last(
        const struct butterflyfish_addable_$t$ *object,
        const $v$*out);

/**
 * @brief Retrieve next item.
 * @param [in] object addable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_addable_$t$_next(
        const struct butterflyfish_addable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object addable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_addable_$t$_prev(
        const struct butterflyfish_addable_$t$ *object,
        const $v$item,
        const $v$*out);

/**
 * @brief Add value.
 * @param [in] object addable instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID if value is invalid.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @note <b>value</b> is copied.
 */
int butterflyfish_addable_$t$_add(
        struct butterflyfish_addable_$t$ *object,
        const $v$value);

/**
 * @brief Add all the values.
 * @param [in] object addable instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add streamed values.
 * @note streamed <b>values</b> are copied.
 */
int butterflyfish_addable_$t$_add_all(
        struct butterflyfish_addable_$t$ *object,
        const struct butterflyfish_stream_$t$ *other);

#endif /* _BUTTERFLYFISH_ADDABLE_$T$_H_ */
