#ifndef _BUTTERFLYFISH_STREAM_P_H_
#define _BUTTERFLYFISH_STREAM_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#define BUTTERFLYFISH_STREAM_P_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STREAM_P_ERROR_ITEM_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STREAM_P_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STREAM_P_ERROR_STREAM_IS_EMPTY \
    SEA_URCHIN_ERROR_IS_EMPTY
#define BUTTERFLYFISH_STREAM_P_ERROR_END_OF_SEQUENCE \
    SEA_URCHIN_ERROR_END_OF_SEQUENCE

struct butterflyfish_stream_p {
    int (*const first)(const void *object,
                       const void **out);

    int (*const next)(const void *object,
                      const void *item,
                      const void **out);
};

/**
 * @brief First item of the stream.
 * @param [in] object stream instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_STREAM_IS_EMPTY if stream is empty.
 */
int butterflyfish_stream_p_first(
        const struct butterflyfish_stream_p *object,
        const void **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stream instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_P_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_stream_p_next(
        const struct butterflyfish_stream_p *object,
        const void *item,
        const void **out);

#endif /* _BUTTERFLYFISH_STREAM_P_H_ */
