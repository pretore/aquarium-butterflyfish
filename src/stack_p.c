#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_stack_p **) object)

#pragma mark stream_p -

int butterflyfish_stack_p_first(
        const struct butterflyfish_stack_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .collection_p
            .stream_p
            .first(object, out);
}

int butterflyfish_stack_p_next(
        const struct butterflyfish_stack_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .collection_p
            .stream_p
            .next(object, item, out);
}

#pragma mark collection_p -

int butterflyfish_stack_p_count(
        const struct butterflyfish_stack_p *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .collection_p
            .count(object, out);
}

int butterflyfish_stack_p_last(
        const struct butterflyfish_stack_p *const object,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .collection_p
            .last(object, out);
}

int butterflyfish_stack_p_prev(
        const struct butterflyfish_stack_p *const object,
        const void *const item,
        const void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_STACK_P_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .collection_p
            .prev(object, item, out);
}

#pragma mark reducible_stack_p -

int butterflyfish_stack_p_pop(
        struct butterflyfish_stack_p *const object,
        void **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->reducible_stack_p
            .pop(object, out);
}

#pragma mark stack_p -

int butterflyfish_stack_p_as_stream(
        const struct butterflyfish_stack_p *const object,
        const struct butterflyfish_stream_p **const out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_p *)
            &object->reducible_stack_p.collection_p.stream_p;
    return 0;
}

int butterflyfish_stack_p_as_collection(
        const struct butterflyfish_stack_p *object,
        const struct butterflyfish_collection_p **out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_p *)
            &object->reducible_stack_p.collection_p;
    return 0;
}

int butterflyfish_stack_p_as_reducible_stack(
        struct butterflyfish_stack_p *object,
        struct butterflyfish_reducible_stack_p **out) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_STACK_P_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_reducible_stack_p *)
            &object->reducible_stack_p;
    return 0;
}

int butterflyfish_stack_p_push(
        struct butterflyfish_stack_p *const object,
        const void *const value) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    return INVOKABLE->push(object, value);
}

int butterflyfish_stack_p_push_all(
        struct butterflyfish_stack_p *const object,
        const struct butterflyfish_stream_p *const other) {
    if (!object) {
        return BUTTERFLYFISH_STACK_P_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_STACK_P_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->push_all(object, other);
}
