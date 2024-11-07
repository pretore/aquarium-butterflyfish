#ifndef _BUTTERFLYFISH_ADDABLE_I_H_
#define _BUTTERFLYFISH_ADDABLE_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "collection_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ADDABLE_I_ERROR_ADDABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_ADDABLE_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ADDABLE_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ADDABLE_I_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_addable_i {
    int (*const as_collection)(const struct butterflyfish_addable_i *object,
                               const struct butterflyfish_collection_i **out);

    int (*const add)(struct butterflyfish_addable_i *object,
                     const struct sea_turtle_integer *value);

    int (*const add_all)(struct butterflyfish_addable_i *object,
                         const struct butterflyfish_stream_i *other);
};

/**
 * @brief Return addable as a stream.
 * @param [in] object addable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_i_as_stream(
        const struct butterflyfish_addable_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return addable as a collection.
 * @param [in] object addable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_i_as_collection(
        const struct butterflyfish_addable_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_addable_i_count(
        const struct butterflyfish_addable_i *object,
        uintmax_t *out);

/**
 * @brief First item of addable.
 * @param [in] object addable instance.
 * @param [out] out receive the first item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_ADDABLE_IS_EMPTY if addable is empty.
 */
int butterflyfish_addable_i_first(
        const struct butterflyfish_addable_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of addable.
 * @param [in] object addable instance.
 * @param [out] out receive the last item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_ADDABLE_IS_EMPTY if addable is empty.
 */
int butterflyfish_addable_i_last(
        const struct butterflyfish_addable_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object addable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_addable_i_next(
        const struct butterflyfish_addable_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object addable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_addable_i_prev(
        const struct butterflyfish_addable_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Add value.
 * @param [in] object addable instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_VALUE_IS_INVALID if value is invalid.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @note <b>value</b> is copied.
 */
int butterflyfish_addable_i_add(
        struct butterflyfish_addable_i *object,
        const struct sea_turtle_integer *value);

/**
 * @brief Add all the values.
 * @param [in] object addable instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ADDABLE_I_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add streamed values.
 * @note streamed <b>values</b> are copied.
 */
int butterflyfish_addable_i_add_all(
        struct butterflyfish_addable_i *object,
        const struct butterflyfish_stream_i *other);

#endif /* _BUTTERFLYFISH_ADDABLE_I_H_ */
