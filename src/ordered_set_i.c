#include <stdlib.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKABLE   (*(struct butterflyfish_ordered_set_i **) object)

#pragma mark stream_i -

int butterflyfish_ordered_set_i_first(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .collection_i
            .stream_i
            .first(object, out);
}

int butterflyfish_ordered_set_i_next(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .collection_i
            .stream_i
            .next(object, item, out);
}

#pragma mark collection_i -

int butterflyfish_ordered_set_i_count(
        const struct butterflyfish_ordered_set_i *const object,
        uintmax_t *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .collection_i
            .count(object, out);
}

int butterflyfish_ordered_set_i_last(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .collection_i
            .last(object, out);
}

int butterflyfish_ordered_set_i_prev(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const item,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .collection_i
            .prev(object, item, out);
}

#pragma mark set_i -

int butterflyfish_ordered_set_i_add(
        struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_i
            .add(object, value);
}

int butterflyfish_ordered_set_i_add_all(
        struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_i
            .add_all(object, other);
}

int butterflyfish_ordered_set_i_remove(
        struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const value) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL;
    }
    return INVOKABLE->set_i
            .remove(object, value);
}

int butterflyfish_ordered_set_i_remove_all(
        struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_i
            .remove_all(object, other);
}

int butterflyfish_ordered_set_i_remove_item(
        struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const item) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_IS_NULL;
    }
    return INVOKABLE->set_i
            .remove_item(object, item);
}

int butterflyfish_ordered_set_i_remove_all_items(
        struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_i
            .remove_all_items(object, other);
}

int butterflyfish_ordered_set_i_contains(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const value,
        bool *const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .contains(object, value, out);
}

int butterflyfish_ordered_set_i_contains_all(
        const struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i *const other,
        bool *out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .contains_all(object, other, out);
}

int butterflyfish_ordered_set_i_retain_all(
        struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i *const other) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OTHER_IS_NULL;
    }
    return INVOKABLE->set_i
            .retain_all(object, other);
}

int butterflyfish_ordered_set_i_get(
        const struct butterflyfish_ordered_set_i *const object,
        const struct sea_turtle_integer *const value,
        const struct sea_turtle_integer **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    return INVOKABLE->set_i
            .get(object, value, out);
}

#pragma mark ordered_set_i -

int butterflyfish_ordered_set_i_as_stream(
        const struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_stream_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_stream_i *)
            &object->set_i.collection_i.stream_i;
    return 0;
}

int butterflyfish_ordered_set_i_as_collection(
        const struct butterflyfish_ordered_set_i *const object,
        const struct butterflyfish_collection_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    *out = (const struct butterflyfish_collection_i *)
            &object->set_i.collection_i;
    return 0;
}

int butterflyfish_ordered_set_i_as_set(
        struct butterflyfish_ordered_set_i *const object,
        struct butterflyfish_set_i **const out) {
    if (!object) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return BUTTERFLYFISH_ORDERED_SET_I_ERROR_OUT_IS_NULL;
    }
    *out = (struct butterflyfish_set_i *) &object->set_i;
    return 0;
}
