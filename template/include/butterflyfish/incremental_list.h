#ifndef _BUTTERFLYFISH_INCREMENTAL_LIST_$T$_H_
#define _BUTTERFLYFISH_INCREMENTAL_LIST_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "list_$t$.h"
#include "addable_$t$.h"

$d$

#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_LIST_$T$_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_LIST_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_incremental_list_$t$ {
    const struct butterflyfish_stream_$t$ *const as_stream;
    const struct butterflyfish_collection_$t$ *const as_collection;
    const struct butterflyfish_list_$t$ *const as_list;
    const struct butterflyfish_addable_$t$ *const as_addable;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if list
     * is empty. 
     */
    int (*const first)(const void *object,
                       const $v$*out);

    /**
     * @brief Last item of the list.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_LIST_IS_EMPTY if list
     * is empty.
     */
    int (*const last)(const void *object,
                      const $v$*out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if item
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
     * there is no next item.
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
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if item
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_END_OF_SEQUENCE if
     * there is no previous item.
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
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS
     * if at does not refer to an item contained within the list.
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
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_IS_NULL if item
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_ITEM_NOT_FOUND if
     * item is not contained within the list.
     */
    int (*const at)(const void *object,
                    const $v$item,
                    uintmax_t *out);

    /**
     * @brief Add value.
     * @param [in] object instance.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_OBJECT_IS_NULL if
     * object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_NULL if
     * value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_VALUE_IS_INVALID if
     * value is invalid.
     * @throws BUTTERFLYFISH_INCREMENTAL_LIST_$T$_ERROR_MEMORY_ALLOCATION_FAILED if
     * there is insufficient memory to add value.
     * @note <b>value</b> is copied.
     */
    int (*const add)(void *object,
                     const $v$value);

};

#endif /* _BUTTERFLYFISH_INCREMENTAL_LIST_$T$_H_ */
