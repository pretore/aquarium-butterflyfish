#ifndef _BUTTERFLYFISH_COLLECTION_I_I_H_
#define _BUTTERFLYFISH_COLLECTION_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_i_i.h"

#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_STREAM_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_i_i {
    const struct butterflyfish_stream_i_i stream_i_i;

    int (*const count)(const void *object,
                       uintmax_t *out);

    int (*const last)(const void *object,
                      const struct butterflyfish_map_entry_i_i **out);

    int (*const prev)(const void *object,
                      const struct butterflyfish_map_entry_i_i *entry,
                      const struct butterflyfish_map_entry_i_i **out);
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
 * @brief Retrieve the count of entries.
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
 * @brief First entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_i_i_first(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Last entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_i_i_last(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next entry.
 */
int butterflyfish_collection_i_i_next(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous entry.
 */
int butterflyfish_collection_i_i_prev(
        const struct butterflyfish_collection_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct butterflyfish_map_entry_i_i **out);

#endif /* _BUTTERFLYFISH_COLLECTION_I_I_H_ */
