#ifndef _BUTTERFLYFISH_SORTED_I_H_
#define _BUTTERFLYFISH_SORTED_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "collection_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_I_ERROR_SORTED_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_SORTED_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_I_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_sorted_i {
    int (*const as_collection)(const struct butterflyfish_sorted_i *object,
                               const struct butterflyfish_collection_i **out);

    int (*const ceiling)(const struct butterflyfish_sorted_i *object,
                         const struct sea_turtle_integer *value,
                         const struct sea_turtle_integer **out);

    int (*const floor)(const struct butterflyfish_sorted_i *object,
                       const struct sea_turtle_integer *value,
                       const struct sea_turtle_integer **out);

    int (*const higher)(const struct butterflyfish_sorted_i *object,
                        const struct sea_turtle_integer *value,
                        const struct sea_turtle_integer **out);

    int (*const lower)(const struct butterflyfish_sorted_i *object,
                       const struct sea_turtle_integer *value,
                       const struct sea_turtle_integer **out);
};

/**
 * @brief Return sorted as a stream.
 * @param [in] object sorted instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_i_as_stream(
        const struct butterflyfish_sorted_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return sorted as a collection.
 * @param [in] object sorted instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_i_as_collection(
        const struct butterflyfish_sorted_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_i_count(
        const struct butterflyfish_sorted_i *object,
        uintmax_t *out);

/**
 * @brief First item of sorted.
 * @param [in] object sorted instance.
 * @param [out] out receive the first item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_SORTED_IS_EMPTY if swappable is empty.
 */
int butterflyfish_sorted_i_first(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of sorted.
 * @param [in] object sorted instance.
 * @param [out] out receive the last item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_SORTED_IS_EMPTY if swappable is empty.
 */
int butterflyfish_sorted_i_last(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_sorted_i_next(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_sorted_i_prev(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND if no value in sorted
 * was equal to or higher than value.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_i_ceiling(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND if no value in sorted
 * was equal to or lower than value.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_i_floor(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND if no value in sorted
 * is greater.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_i_higher(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_VALUE_NOT_FOUND if no value in sorted
 * is lower.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_i_lower(
        const struct butterflyfish_sorted_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

#endif /* _BUTTERFLYFISH_SORTED_I_H_ */
