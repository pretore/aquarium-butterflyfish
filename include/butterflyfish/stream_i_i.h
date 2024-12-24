#ifndef _BUTTERFLYFISH_STREAM_I_I_H_
#define _BUTTERFLYFISH_STREAM_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL \
    SEA_URCHIN_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL \
    SEA_URCHIN_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL \
    SEA_URCHIN_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY \
    SEA_URCHIN_ERROR_IS_EMPTY
#define BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE \
    SEA_URCHIN_ERROR_END_OF_SEQUENCE

struct butterflyfish_stream_i_i {
    /**
     * @brief First item of the stream.
     * @param [in] object instance.
     * @param [out] out receive the item
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY if stream is empty.
     */
    int (*const first)(const void *object,
                       const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE if there is no next
     * item.
     */
    int (*const next)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);
};

#endif /* _BUTTERFLYFISH_STREAM_I_I_H_ */
