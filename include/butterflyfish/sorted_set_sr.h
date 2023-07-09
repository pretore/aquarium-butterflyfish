#ifndef _BUTTERFLYFISH_SORTED_SET_SR_H_
#define _BUTTERFLYFISH_SORTED_SET_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_set_sr.h"

struct triggerfish_strong;

#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND

struct butterflyfish_sorted_set_sr {
    const struct butterflyfish_ordered_set_sr ordered_set_sr;

    int (*const first)(const void *object,
                       struct triggerfish_strong **out);

    int (*const next)(const void *object,
                      const struct triggerfish_strong *item,
                      struct triggerfish_strong **out);

    int (*const last)(const void *object,
                      struct triggerfish_strong **out);

    int (*const prev)(const void *object,
                      const struct triggerfish_strong *item,
                      struct triggerfish_strong **out);

    int (*const ceiling)(const void *object,
                         const struct triggerfish_strong *value,
                         struct triggerfish_strong **out);

    int (*const floor)(const void *object,
                       const struct triggerfish_strong *value,
                       struct triggerfish_strong **out);

    int (*const higher)(const void *object,
                        const struct triggerfish_strong *value,
                        struct triggerfish_strong **out);

    int (*const lower)(const void *object,
                       const struct triggerfish_strong *value,
                       struct triggerfish_strong **out);
};

/**
 * @brief Return sorted set as a stream.
 * @param [in] object set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_as_stream(
        const struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr **out);

/**
 * @brief Return sorted set as a collection.
 * @param [in] object sorted set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_as_collection(
        const struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_collection_sr **out);

/**
 * @brief Return sorted set as a set.
 * @param [in] object sorted set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_as_set(
        struct butterflyfish_sorted_set_sr *object,
        struct butterflyfish_set_sr **out);

/**
 * @brief Return sorted set as a ordered set.
 * @param [in] object sorted set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_as_ordered_set(
        struct butterflyfish_sorted_set_sr *object,
        struct butterflyfish_ordered_set_sr **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_count(
        const struct butterflyfish_sorted_set_sr *object,
        uintmax_t *out);

/**
 * @brief First item of the sorted set.
 * @param [in] object sorted set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_SET_IS_EMPTY if sorted set is
 * empty.
 */
int butterflyfish_sorted_set_sr_first(
        const struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Last item of the sorted set.
 * @param [in] object sorted set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_SET_IS_EMPTY if sorted set is
 * empty.
 */
int butterflyfish_sorted_set_sr_last(
        const struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Remove item.
 * @param [in] object sorted set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_remove_item(
        struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong *item);

/**
 * @brief Remove all items.
 * @param [in] object sorted set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_set_sr_remove_all_items(
        struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_sorted_set_sr_next(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_sorted_set_sr_prev(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Add value to the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present in the sorted set.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add value to the sorted set.
 */
int butterflyfish_sorted_set_sr_add(
        struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong *value);

/**
 * @brief Add values to the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be added, ignoring duplicates.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add streamed values to the sorted set.
 */
int butterflyfish_sorted_set_sr_add_all(
        struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Remove value from the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is 
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_NOT_FOUND if value is not
 * in the sorted set instance.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_sorted_set_sr_remove(
        struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong *value);

/**
 * @brief Remove values from the sorted set.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be removed, ignoring value not
 * found.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the streamed values in the sorted set.
 */
int butterflyfish_sorted_set_sr_remove_all(
        struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Check if sorted set contains the given value.
 * @param [in] object sorted set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_contains(
        const struct butterflyfish_sorted_set_sr *object,
        struct triggerfish_strong *value,
        bool *out);

/**
 * @brief Check if sorted set contains all the given values.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values will be checked for presence in
 * sorted set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_contains_all(
        const struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr *other,
        bool *out);

/**
 * @brief Retain all the values present in both.
 * @param [in] object sorted set instance.
 * @param [in] other stream whose values, if present in sorted set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_retain_all(
        struct butterflyfish_sorted_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Retrieve item for value.
 * @param [in] object sorted set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND if there is no
 * item that matched value.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_get(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted set instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND if no item matched
 * value or a higher value.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_ceiling(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted set instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND if no item matched
 * value or a lower value.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_floor(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted set instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND if there is no
 * greater value.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_higher(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted set instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_ITEM_NOT_FOUND if there is no
 * lower value.
 * @throws BUTTERFLYFISH_SORTED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_set_sr_lower(
        const struct butterflyfish_sorted_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

#endif /* _BUTTERFLYFISH_SORTED_SET_SR_H_ */
