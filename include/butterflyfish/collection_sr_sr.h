#ifndef _BUTTERFLYFISH_COLLECTION_SR_SR_H_
#define _BUTTERFLYFISH_COLLECTION_SR_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_sr_sr.h"

#define BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_SR_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_SR_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_SR_SR_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_STREAM_SR_SR_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_SR_SR_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_sr_sr {
    const struct butterflyfish_stream_sr_sr stream_sr_sr;

    int (*const count)(const void *object,
                       uintmax_t *out);

    int (*const last)(const void *object,
                      struct butterflyfish_map_entry_sr_sr **out);

    int (*const prev)(const void *object,
                      const struct butterflyfish_map_entry_sr_sr *entry,
                      struct butterflyfish_map_entry_sr_sr **out);
};

/**
 * @brief Return collection as a stream.
 * @param [in] object collection instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_collection_sr_sr_as_stream(
        const struct butterflyfish_collection_sr_sr *object,
        const struct butterflyfish_stream_sr_sr **out);

/**
 * @brief Retrieve the count of entries.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_sr_sr_count(
        const struct butterflyfish_collection_sr_sr *object,
        uintmax_t *out);

/**
 * @brief First entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int  butterflyfish_collection_sr_sr_first(
        const struct butterflyfish_collection_sr_sr *object,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Last entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_sr_sr_last(
        const struct butterflyfish_collection_sr_sr *object,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE if there is no
 * next entry.
 */
int butterflyfish_collection_sr_sr_next(
        const struct butterflyfish_collection_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ITEM_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE if there is no
 * previous entry.
 */
int butterflyfish_collection_sr_sr_prev(
        const struct butterflyfish_collection_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct butterflyfish_map_entry_sr_sr **out);

#endif /* _BUTTERFLYFISH_COLLECTION_SR_SR_H_ */
