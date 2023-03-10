#ifndef _BUTTERFLYFISH_SET_NI_H_
#define _BUTTERFLYFISH_SET_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_ni.h"

#define BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SET_NI_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_SET_NI_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SET_NI_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SET_NI_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SET_NI_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_SET_NI_ERROR_ITEM_NOT_FOUND \
    SEA_URCHIN_ERROR_ITEM_NOT_FOUND

struct butterflyfish_set_ni {
    const struct butterflyfish_collection_ni collection_ni;

    int (*const add)(void *object,
                     uintmax_t value);

    int (*const remove)(void *object,
                        uintmax_t value);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_ni *other);

    int (*const remove_all)(void *object,
                            const struct butterflyfish_stream_ni *other);

    int (*const remove_item)(void *object,
                             const uintmax_t *item);

    int (*const remove_all_items)(void *object,
                                  const struct butterflyfish_stream_ni *other);

    int (*const contains)(const void *object,
                          uintmax_t value,
                          bool *out);

    int (*const contains_all)(const void *object,
                              const struct butterflyfish_stream_ni *other,
                              bool *out);

    int (*const retain_all)(void *object,
                            const struct butterflyfish_stream_ni *other);

    int (*const get)(const void *object,
                     uintmax_t value,
                     const uintmax_t **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_set_ni_count(
        const struct butterflyfish_set_ni *object,
        uintmax_t *out);

/**
 * @brief First item of the set.
 * @param [in] object set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_SET_IS_EMPTY if set is empty.
 */
int butterflyfish_set_ni_first(
        const struct butterflyfish_set_ni *object,
        const uintmax_t **out);

/**
 * @brief Last item of the set.
 * @param [in] object set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_SET_IS_EMPTY if set is empty.
 */
int butterflyfish_set_ni_last(
        const struct butterflyfish_set_ni *object,
        const uintmax_t **out);

/**
 * @brief Remove item.
 * @param [in] object set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 */
int butterflyfish_set_ni_remove_item(
        struct butterflyfish_set_ni *object,
        const uintmax_t *item);

/**
 * @brief Remove all items.
 * @param [in] object set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 */
int butterflyfish_set_ni_remove_all_items(
        struct butterflyfish_set_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Retrieve next item.
 * @param [in] object set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_set_ni_next(
        const struct butterflyfish_set_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_END_OF_SEQUENCE if there is no previous
 * item.
 */
int butterflyfish_set_ni_prev(
        const struct butterflyfish_set_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Add value to the set.
 * @param [in] object set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_VALUE_ALREADY_EXISTS if value is already
 * present in the set.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value to the set.
 * @note <b>value</b> is copied and then placed into the set.
 */
int butterflyfish_set_ni_add(
        struct butterflyfish_set_ni *object,
        uintmax_t value);

/**
 * @brief Add values to the set.
 * @param [in] object set instance.
 * @param [in] other stream whose values will be added, ignoring duplicates.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add streamed values to the set.
 * @note streamed <b>values</b> are copied and then placed into the set.
 */
int butterflyfish_set_ni_add_all(
        struct butterflyfish_set_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Remove value from the set.
 * @param [in] object set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_VALUE_NOT_FOUND if value is not in the
 * set instance.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the value.
 */
int butterflyfish_set_ni_remove(
        struct butterflyfish_set_ni *object,
        uintmax_t value);

/**
 * @brief Remove values from the set.
 * @param [in] object set instance.
 * @param [in] other stream whose values will be removed, ignoring value not
 * found.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the streamed values in the set.
 */
int butterflyfish_set_ni_remove_all(
        struct butterflyfish_set_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Check if set contains the given value.
 * @param [in] object set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the item.
 */
int butterflyfish_set_ni_contains(
        const struct butterflyfish_set_ni *object,
        uintmax_t value,
        bool *out);

/**
 * @brief Check if set contains all the given values.
 * @param [in] object set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the item.
 */
int butterflyfish_set_ni_contains_all(
        const struct butterflyfish_set_ni *object,
        const struct butterflyfish_stream_ni *other,
        bool *out);

/**
 * @brief Retain all the values present in both.
 * @param [in] object set instance.
 * @param [in] other stream whose values, if present in set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the item.
 */
int butterflyfish_set_ni_retain_all(
        struct butterflyfish_set_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Retrieve item for value.
 * @param [in] object set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_ITEM_NOT_FOUND if there is no item that
 * matched value.
 * @throws BUTTERFLYFISH_SET_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to find the item.
 */
int butterflyfish_set_ni_get(
        const struct butterflyfish_set_ni *object,
        uintmax_t value,
        const uintmax_t **out);

#endif /* _BUTTERFLYFISH_SET_NI_H_ */
