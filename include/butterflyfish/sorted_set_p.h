#ifndef _BUTTERFLYFISH_SORTED_SET_P_H_
#define _BUTTERFLYFISH_SORTED_SET_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_set_p.h"

#define BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SET_P_ERROR_ITEM_NOT_FOUND

struct butterflyfish_sorted_set_p {
    const struct butterflyfish_ordered_set_p ordered_set_p;

    int (*const first)(const void *object,
                       const void **out);

    int (*const next)(const void *object,
                      const void *item,
                      const void **out);

    int (*const last)(const void *object,
                      const void **out);

    int (*const prev)(const void *object,
                      const void *item,
                      const void **out);

    int (*const ceiling)(const void *object,
                         const void *value,
                         const void **out);

    int (*const floor)(const void *object,
                       const void *value,
                       const void **out);

    int (*const higher)(const void *object,
                        const void *value,
                        const void **out);

    int (*const lower)(const void *object,
                       const void *value,
                       const void **out);
};

/**
 * @brief Return sorted set as a stream.
 * @param [in] object set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_as_stream(
        const struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p **out);

/**
 * @brief Return sorted set as a collection.
 * @param [in] object sorted set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_as_collection(
        const struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_collection_p **out);

/**
 * @brief Return sorted set as a set.
 * @param [in] object sorted set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_as_set(
        struct butterflyfish_sorted_set_p *object,
        struct butterflyfish_set_p **out);

/**
 * @brief Return sorted set as a ordered set.
 * @param [in] object sorted set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_as_ordered_set(
        struct butterflyfish_sorted_set_p *object,
        struct butterflyfish_ordered_set_p **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_count(
        const struct butterflyfish_sorted_set_p *object,
        uintmax_t *out);

/**
 * @brief First item of the sorted set.
 * @param [in] object sorted set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_SET_IS_EMPTY if sorted set is
 * empty.
 */
int butterflyfish_sorted_set_p_first(
        const struct butterflyfish_sorted_set_p *object,
        const void **out);

/**
 * @brief Last item of the sorted set.
 * @param [in] object sorted set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_SET_IS_EMPTY if sorted set is
 * empty.
 */
int butterflyfish_sorted_set_p_last(
        const struct butterflyfish_sorted_set_p *object,
        const void **out);

/**
 * @brief Remove item.
 * @param [in] object sorted set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_remove_item(
        struct butterflyfish_sorted_set_p *object,
        const void *item);

/**
 * @brief Remove all items.
 * @param [in] object sorted set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_set_p_remove_all_items(
        struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_sorted_set_p_next(
        const struct butterflyfish_sorted_set_p *object,
        const void *item,
        const void **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_sorted_set_p_prev(
        const struct butterflyfish_sorted_set_p *object,
        const void *item,
        const void **out);

/**
 * @brief Add value to the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present in the sorted set.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add value to the sorted set.
 * @note <b>value</b> is copied and then placed into the sorted set.
 */
int butterflyfish_sorted_set_p_add(
        struct butterflyfish_sorted_set_p *object,
        const void *value);

/**
 * @brief Add values to the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be added, ignoring duplicates.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add streamed values to the sorted set.
 * @note streamed <b>values</b> are copied and then placed into the sorted set.
 */
int butterflyfish_sorted_set_p_add_all(
        struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Remove value from the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_VALUE_NOT_FOUND if value is not
 * in the sorted set instance.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_sorted_set_p_remove(
        struct butterflyfish_sorted_set_p *object,
        const void *value);

/**
 * @brief Remove values from the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be removed, ignoring value not
 * found.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the streamed values in the sorted set.
 */
int butterflyfish_sorted_set_p_remove_all(
        struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Check if sorted set contains the given value.
 * @param [in] object sorted set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_contains(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        bool *out);

/**
 * @brief Check if sorted set contains all the given values.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be checked for presence in
 * sorted set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_contains_all(
        const struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p *other,
        bool *out);

/**
 * @brief Retain all the values present in both.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values, if present in sorted set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_retain_all(
        struct butterflyfish_sorted_set_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Retrieve item for value.
 * @param [in] object sorted set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND if there is no
 * item that matched value.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_get(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        const void **out);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted set instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND if no item matched
 * value or a higher value.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_ceiling(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        const void **out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted set instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND if no item matched
 * value or a lower value.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_floor(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        const void **out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted set instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND if there is no
 * greater value.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_higher(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        const void **out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted set instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_ITEM_NOT_FOUND if there is no
 * lower value.
 * @throws BUTTERFLYFISH_SORTED_SET_P_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_p_lower(
        const struct butterflyfish_sorted_set_p *object,
        const void *value,
        const void **out);

#endif /* _BUTTERFLYFISH_SORTED_SET_P_H_ */
