#ifndef _BUTTERFLYFISH_SETTABLE_LIST_$T$_H_
#define _BUTTERFLYFISH_SETTABLE_LIST_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "list_$t$.h"
#include "settable_$t$.h"

$d$

#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_LIST_$T$_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_LIST_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_$T$_ERROR_VALUE_IS_INVALID

struct butterflyfish_settable_list_$t$ {
    const struct butterflyfish_stream_$t$ *const as_stream;
    const struct butterflyfish_collection_$t$ *const as_collection;
    const struct butterflyfish_list_$t$ *const as_list;
    const struct butterflyfish_settable_$t$ *const as_settable;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_LIST_IS_EMPTY if list is
     * empty.
     */
    int (*const first)(const void *object,
                       const $v$*out);

    /**
     * @brief Last item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_LIST_IS_EMPTY if list is
     * empty.
     */
    int (*const last)(const void *object,
                      const $v$*out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_END_OF_SEQUENCE if there
     * is no next item.
     */
    int (*const next)(const void *object,
                      const $v$item,
                      const $v$*out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_END_OF_SEQUENCE if there
     * is no previous item.
     */
    int (*const prev)(const void *object,
                      const $v$item,
                      const $v$*out);

    /**
     * @brief Retrieve item at index.
     * @param [in] object instance.
     * @param [in] at index of item to retrieve.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS if
     * at does not refer to an item contained within the list.
     */
    int (*const get)(const void *object,
                     uintmax_t at,
                     const $v$*out);

    /**
     * @brief Get index of item.
     * @param [in] object instance.
     * @param [in] item whose index we are to determine.
     * @param [out] out receive index of item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_NOT_FOUND if item is
     * not contained within the list.
     */
    int (*const at)(const void *object,
                    const $v$item,
                    uintmax_t *out);

    /**
     * @brief Set value for item.
     * @param [in] object instance.
     * @param [in] item to set.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_INVALID if
     * value is invalid.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @note <b>value</b> is copied and then item is set to it.
     */
    int (*const set_item)(void *object,
                          const $v$item,
                          const $v$value);

    /**
     * @brief Set value of item at index.
     * @param [in] object instance.
     * @param [in] at index of item to set.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
     * if at does not refer to an item contained within the list.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @throws BUTTERFLYFISH_SETTABLE_LIST_$T$_ERROR_VALUE_IS_INVALID if
     * value is invalid.
     * @note <b>value</b> is copied and then item at index is set to it.
     */
    int (*const set)(void *object,
                     uintmax_t at,
                     const $v$value);
};

#endif /* _BUTTERFLYFISH_SETTABLE_LIST_$T$_H_ */
