#ifndef _BUTTERFLYFISH_COLLECTION_S_S_H_
#define _BUTTERFLYFISH_COLLECTION_S_S_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "stream_s_s.h"

#define BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_STREAM_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_COLLECTION_S_S_ERROR_COLLECTION_IS_EMPTY \
    BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY
#define BUTTERFLYFISH_COLLECTION_S_S_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_STREAM_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_COLLECTION_S_S_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE

struct butterflyfish_collection_s_s {
    const struct butterflyfish_stream_s_s stream_s_s;

    int (*const count)(const void *object,
                       uintmax_t *out);

    int (*const last)(const void *object,
                      struct butterflyfish_map_entry_s_s **out);

    int (*const prev)(const void *object,
                      const struct butterflyfish_map_entry_s_s *entry,
                      struct butterflyfish_map_entry_s_s **out);
};

/**
 * @brief Retrieve the count of entries.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_collection_s_s_count(
        const struct butterflyfish_collection_s_s *object,
        uintmax_t *out);

/**
 * @brief First entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int  butterflyfish_collection_s_s_first(
        const struct butterflyfish_collection_s_s *object,
        struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Last entry of the collection.
 * @param [in] object collection instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_COLLECTION_IS_EMPTY if collection
 * is empty.
 */
int butterflyfish_collection_s_s_last(
        const struct butterflyfish_collection_s_s *object,
        struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_END_OF_SEQUENCE if there is no
 * next entry.
 */
int butterflyfish_collection_s_s_next(
        const struct butterflyfish_collection_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object collection instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_ITEM_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_COLLECTION_S_S_ERROR_END_OF_SEQUENCE if there is no
 * previous entry.
 */
int butterflyfish_collection_s_s_prev(
        const struct butterflyfish_collection_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        struct butterflyfish_map_entry_s_s **out);

#endif /* _BUTTERFLYFISH_COLLECTION_S_S_H_ */
