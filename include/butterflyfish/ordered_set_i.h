#ifndef _BUTTERFLYFISH_ORDERED_SET_I_H_
#define _BUTTERFLYFISH_ORDERED_SET_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_i.h"
#include "set_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SET_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SET_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_ordered_set_i {
    int (*const as_ordered)(
            const struct butterflyfish_ordered_set_i *object,
            const struct butterflyfish_ordered_i **out);

    int (*const as_set)(
            const struct butterflyfish_ordered_set_i *object,
            const struct butterflyfish_set_i **out);
};

/**
 * @brief Return ordered set as a stream.
 * @param [in] object set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_i_as_stream(
        const struct butterflyfish_ordered_set_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return ordered set as a collection.
 * @param [in] object ordered set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_i_as_collection(
        const struct butterflyfish_ordered_set_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return ordered set as an ordered.
 * @param [in] object ordered set instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_i_as_ordered(
        const struct butterflyfish_ordered_set_i *object,
        const struct butterflyfish_ordered_i **out);

/**
 * @brief Return ordered set as a set.
 * @param [in] object ordered set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_i_as_set(
        const struct butterflyfish_ordered_set_i *object,
        const struct butterflyfish_set_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_i_count(
        const struct butterflyfish_ordered_set_i *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_i_first(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_i_last(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_ordered_set_i_next(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_ordered_set_i_prev(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Check if ordered set contains the given value.
 * @param [in] object ordered set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_i_contains(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if ordered set contains all the given values.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_i_contains_all(
        const struct butterflyfish_ordered_set_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object ordered set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_NOT_FOUND if value is not
 * in the ordered instance.
 * @throws BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_i_get(
        const struct butterflyfish_ordered_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

#endif /* _BUTTERFLYFISH_ORDERED_SET_I_H_ */
