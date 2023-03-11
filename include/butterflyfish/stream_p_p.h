#ifndef _BUTTERFLYFISH_STREAM_P_P_H_
#define _BUTTERFLYFISH_STREAM_P_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#define BUTTERFLYFISH_STREAM_P_P_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STREAM_P_P_ERROR_ENTRY_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STREAM_P_P_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STREAM_P_P_ERROR_STREAM_IS_EMPTY \
    SEA_URCHIN_ERROR_IS_EMPTY
#define BUTTERFLYFISH_STREAM_P_P_ERROR_END_OF_SEQUENCE \
    SEA_URCHIN_ERROR_END_OF_SEQUENCE

struct butterflyfish_map_entry_p_p;

struct butterflyfish_stream_p_p {
    int (*const first)(const void *object,
                       struct butterflyfish_map_entry_p_p **out);

    int (*const next)(const void *object,
                      const struct butterflyfish_map_entry_p_p *entry,
                      struct butterflyfish_map_entry_p_p **out);
};

/**
 * @brief First entry of the stream.
 * @param [in] object stream instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_STREAM_IS_EMPTY if stream is empty.
 */
int butterflyfish_stream_p_p_first(
        const struct butterflyfish_stream_p_p *object,
        struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object stream instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_P_ERROR_END_OF_SEQUENCE if there is no next
 * entry.
 */
int butterflyfish_stream_p_p_next(
        const struct butterflyfish_stream_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry,
        struct butterflyfish_map_entry_p_p **out);

#endif /* _BUTTERFLYFISH_STREAM_P_P_H_ */
