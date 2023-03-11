#ifndef _BUTTERFLYFISH_QUEUE_P_H_
#define _BUTTERFLYFISH_QUEUE_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_p.h"

#define BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_QUEUE_P_ERROR_QUEUE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_P_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_QUEUE_P_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_QUEUE_P_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_P_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_QUEUE_P_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_QUEUE_P_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_queue_p {
    const struct butterflyfish_collection_p collection_p;

    int (*const add)(void *object,
                     const void *value);

    int (*const remove)(void *object,
                        void **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_p_count(
        const struct butterflyfish_queue_p *object,
        uintmax_t *out);

/**
 * @brief First item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_p_first(
        const struct butterflyfish_queue_p *object,
        const void **out);

/**
 * @brief Last item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_p_last(
        const struct butterflyfish_queue_p *object,
        const void **out);

/**
 * @brief Retrieve next item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_queue_p_next(
        const struct butterflyfish_queue_p *object,
        const void *item,
        const void **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_queue_p_prev(
        const struct butterflyfish_queue_p *object,
        const void *item,
        const void **out);

/**
 * @brief Add value to the end the queue.
 * @param [in] object queue instance.
 * @param [in] value to add to the end.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @note <b>value</b> is copied and then appended to the queue.
 */
int butterflyfish_queue_p_add(
        struct butterflyfish_queue_p *object,
        const void *value);

/**
 * @brief Remove value from the front the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the value in the front of the queue.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_P_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_p_remove(
        struct butterflyfish_queue_p *object,
        void **out);

#endif /* _BUTTERFLYFISH_QUEUE_P_H_ */
