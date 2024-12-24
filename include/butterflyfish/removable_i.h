#ifndef _BUTTERFLYFISH_REMOVABLE_I_H_
#define _BUTTERFLYFISH_REMOVABLE_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_ERROR_REMOVABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_REMOVABLE_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REMOVABLE_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE

struct butterflyfish_removable_i {
    const struct butterflyfish_stream_i *const as_stream;
    const struct butterflyfish_collection_i *const as_collection;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the removable.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_REMOVABLE_IS_EMPTY if
     * removable is empty.
     */
    int (*const first)(const void *object,
                       const struct sea_turtle_integer **out);

    /**
     * @brief Last item of the removable.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_REMOVABLE_IS_EMPTY if
     * removable is empty.
     */
    int (*const last)(const void *object,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_END_OF_SEQUENCE if there is no
     * next item.
     */
    int (*const next)(const void *object,
                      const struct sea_turtle_integer *item,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_END_OF_SEQUENCE if there is no
     * previous item.
     */
    int (*const prev)(const void *object,
                      const struct sea_turtle_integer *item,
                      const struct sea_turtle_integer **out);

    /**
     * @brief Remove item.
     * @param [in] object instance.
     * @param [in] item to be removed.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_REMOVABLE_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @note <b>item</b> is invalidated when removed.
     */
    int (*const remove_item)(void *object,
                             const struct sea_turtle_integer *item);
};

#endif /* _BUTTERFLYFISH_REMOVABLE_I_H_ */
