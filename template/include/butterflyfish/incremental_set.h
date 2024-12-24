#ifndef _BUTTERFLYFISH_INCREMENTAL_SET_$T$_H_
#define _BUTTERFLYFISH_INCREMENTAL_SET_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "addable_$t$.h"
#include "set_$t$.h"

$d$

#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SET_$T$_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ADDABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ADDABLE_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SET_$T$_ERROR_VALUE_NOT_FOUND

struct butterflyfish_incremental_set_$t$ {
    const struct butterflyfish_stream_$t$ *const as_stream;
    const struct butterflyfish_collection_$t$ *const as_collection;
    const struct butterflyfish_set_$t$ *const as_set;
    const struct butterflyfish_addable_$t$ *const as_addable;

    /**
      * @brief Retrieve the count of items.
      * @param [in] object instance whose count we are to retrieve.
      * @param [out] out receive the count.
      * @return On success <i>0</i>, otherwise an error code.
      * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if
      * object is <i>NULL</i>.
      * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
      * <i>NULL</i>.
      */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the collection.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY if set is
     * empty.
     */
    int (*const first)(const void *object,
                       const $v$*out);

    /**
     * @brief Last item of the set.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_SET_IS_EMPTY if set is
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
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE if there
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
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_END_OF_SEQUENCE if there
     * is no previous item.
     */
    int (*const prev)(const void *object,
                      const $v$item,
                      const $v$*out);

    /**
     * @brief Check if set contains the given value.
     * @param [in] object instance.
     * @param [in] value to check if value is present.
     * @param [out] out receive true if value is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if value
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the item.
     */
    int (*const contains)(const void *object,
                          const $v$value,
                          bool *out);

    /**
     * @brief Retrieve item for value.
     * @param [in] object instance.
     * @param [in] value to find.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if value
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_NOT_FOUND if value
     * is not in the set instance.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the item.
     */
    int (*const get)(const void *object,
                     const $v$value,
                     const $v$*out);

    /**
     * @brief Add value.
     * @param [in] object instance.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL if value
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_INVALID if
     * value is invalid.
     * @throws BUTTERFLYFISH_INCREMENTAL_SET_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value.
     * @note <b>value</b> is copied.
     */
    int (*const add)(void *object,
                     const $v$value);
};

#endif /* _BUTTERFLYFISH_INCREMENTAL_SET_$T$_H_ */
