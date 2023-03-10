#ifndef _BUTTERFLYFISH_COLLECTION_NI_H_
#define _BUTTERFLYFISH_COLLECTION_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_ni.h"

#define BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_NI_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_NI_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_NI_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_STREAM_NI_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_NI_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_ni {
    const struct butterflyfish_stream_ni stream_ni;

    int (*const count)(const void *object,
                       uintmax_t *out);

    int (*const last)(const void *object,
                      const uintmax_t **out);

    int (*const prev)(const void *object,
                      const uintmax_t *item,
                      const uintmax_t **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_ni_count(
        const struct butterflyfish_collection_ni *object,
        uintmax_t *out);

/**
 * @brief First item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_ni_first(
        const struct butterflyfish_collection_ni *object,
        const uintmax_t **out);

/**
 * @brief Last item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_ni_last(
        const struct butterflyfish_collection_ni *object,
        const uintmax_t **out);

/**
 * @brief Retrieve next item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_collection_ni_next(
        const struct butterflyfish_collection_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_collection_ni_prev(
        const struct butterflyfish_collection_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

#endif /* _BUTTERFLYFISH_COLLECTION_NI_H_ */
