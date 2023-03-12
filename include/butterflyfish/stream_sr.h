#ifndef _BUTTERFLYFISH_STREAM_SR_H_
#define _BUTTERFLYFISH_STREAM_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct triggerfish_strong;

#define BUTTERFLYFISH_STREAM_SR_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STREAM_SR_ERROR_ITEM_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STREAM_SR_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STREAM_SR_ERROR_STREAM_IS_EMPTY \
    SEA_URCHIN_ERROR_IS_EMPTY
#define BUTTERFLYFISH_STREAM_SR_ERROR_END_OF_SEQUENCE \
    SEA_URCHIN_ERROR_END_OF_SEQUENCE

struct butterflyfish_stream_sr {
    int (*const first)(const void *object,
                       struct triggerfish_strong **out);

    int (*const next)(const void *object,
                      const struct triggerfish_strong *item,
                      struct triggerfish_strong **out);
};

/**
 * @brief First item of the stream.
 * @param [in] object stream instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_STREAM_IS_EMPTY if stream is empty.
 */
int butterflyfish_stream_sr_first(
        const struct butterflyfish_stream_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stream instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STREAM_SR_ERROR_END_OF_SEQUENCE if there is no next
 * item.
 */
int butterflyfish_stream_sr_next(
        const struct butterflyfish_stream_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

#endif /* _BUTTERFLYFISH_STREAM_SR_H_ */
