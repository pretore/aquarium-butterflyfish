#ifndef _BUTTERFLYFISH_COLLECTION_I_I_H_
#define _BUTTERFLYFISH_COLLECTION_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_i_i {
    int (*const as_stream)(const struct butterflyfish_collection_i_i *object,
                           const struct butterflyfish_stream_i_i **out);

    int (*const count)(const struct butterflyfish_collection_i_i *object,
                       uintmax_t *out);

    int (*const last)(const struct butterflyfish_collection_i_i *object,
                      const struct butterflyfish_map_i_i_entry **out);

    int (*const prev)(const struct butterflyfish_collection_i_i *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);
};

/**
 * @brief Return collection as a stream.
 * @param [in] object collection instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_i_i_as_stream(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_i_i_count(
        const struct butterflyfish_collection_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_i_i_first(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_i_i_last(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_collection_i_i_next(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object collection instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_collection_i_i_prev(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

#endif /* _BUTTERFLYFISH_COLLECTION_I_I_H_ */
