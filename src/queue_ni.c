#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_queue_ni **) object)

#pragma mark stream_ni -

int butterflyfish_queue_ni_first(
        const struct butterflyfish_queue_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .collection_ni
            .stream_ni
            .first(object, out);
}

int butterflyfish_queue_ni_next(
        const struct butterflyfish_queue_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .collection_ni
            .stream_ni
            .next(object, item, out);
}

#pragma mark collection_ni -

int butterflyfish_queue_ni_count(
        const struct butterflyfish_queue_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .collection_ni
            .count(object, out);
}

int butterflyfish_queue_ni_last(
        const struct butterflyfish_queue_ni *const object,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .collection_ni
            .last(object, out);
}

int butterflyfish_queue_ni_prev(
        const struct butterflyfish_queue_ni *const object,
        const uintmax_t *const item,
        const uintmax_t **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .collection_ni
            .prev(object, item, out);
}

#pragma mark reducible_queue_ni -

int butterflyfish_queue_ni_remove(
        struct butterflyfish_queue_ni *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_queue_ni
            .remove(object, out);
}

#pragma mark queue_ni -

int butterflyfish_queue_ni_as_stream(
        const struct butterflyfish_queue_ni *const object,
        const struct butterflyfish_stream_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_ni *)
            &object->reducible_queue_ni.collection_ni.stream_ni;
    return 0;
}

int butterflyfish_queue_ni_as_collection(
        const struct butterflyfish_queue_ni *const object,
        const struct butterflyfish_collection_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_ni *)
            &object->reducible_queue_ni.collection_ni;
    return 0;
}

int butterflyfish_queue_ni_as_reducible_queue(
        struct butterflyfish_queue_ni *const object,
        struct butterflyfish_reducible_queue_ni **const out) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_reducible_queue_ni *)
            &object->reducible_queue_ni;
    return 0;
}

int butterflyfish_queue_ni_add(
        struct butterflyfish_queue_ni *const object,
        const uintmax_t value) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->add(object, value);
}

int butterflyfish_queue_ni_add_all(
        struct butterflyfish_queue_ni *const object,
        const struct butterflyfish_stream_ni *const other) {
    if (!object) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_QUEUE_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->add_all(object, other);
}
