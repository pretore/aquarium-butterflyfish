#include <stdlib.h>
#include <assert.h>
#include <seagrass.h>
#include <butterflyfish.h>

#ifdef TEST
#include <test/cmocka.h>
#endif

#define INVOKE(x) \\
    (*(struct butterflyfish_ordered_settable_incremental_set_$t$ **) x)
#define INVOKE_SETTABLE_INCREMENTAL_SET(x) \\
    (*(struct butterflyfish_settable_incremental_set_$t$ **) x)
#define INVOKE_ORDERED_INCREMENTAL_SET(x) \\
    (*(struct butterflyfish_ordered_incremental_set_$t$ **) x)
#define INVOKE_ORDERED_SETTABLE_SET(x) \\
    (*(struct butterflyfish_ordered_settable_set_$t$ **) x)
#define INVOKE_INCREMENTAL_SET(x) \\
    (*(struct butterflyfish_incremental_set_$t$ **) x)
#define INVOKE_ORDERED_SET(x)   (*(struct butterflyfish_ordered_set_$t$ **) x)
#define INVOKE_INSERTABLE(x)    (*(struct butterflyfish_insertable_$t$ **) x)
#define INVOKE_SETTABLE_SET(x)  (*(struct butterflyfish_settable_set_$t$ **) x)
#define INVOKE_ADDABLE(x)       (*(struct butterflyfish_addable_$t$ **) x)
#define INVOKE_SET(x)           (*(struct butterflyfish_set_$t$ **) x)
#define INVOKE_ORDERED(x)       (*(struct butterflyfish_ordered_$t$ **) x)
#define INVOKE_SETTABLE(x)      (*(struct butterflyfish_settable_$t$ **) x)
#define INVOKE_COLLECTION(x)    (*(struct butterflyfish_collection_$t$ **) x)
#define INVOKE_STREAM(x)        (*(struct butterflyfish_stream_$t$ **) x)

static inline int
as_ordered_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_ordered_incremental_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_incremental_set(object, out);
}

static inline int
as_ordered_settable_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_ordered_settable_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_ordered_settable_set(object, out);
}

static inline int
as_settable_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_incremental_set_$t$ **const out) {
    assert(object);
    assert(out);
    return INVOKE(object)->as_settable_incremental_set(object, out);
}

static inline int
as_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_incremental_set_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_incremental_set_$t$ *ordered_incremental_set;
    seagrass_required_true(!as_ordered_incremental_set(
            object, &ordered_incremental_set));
    return INVOKE_ORDERED_INCREMENTAL_SET(ordered_incremental_set)
        ->as_incremental_set(ordered_incremental_set, out);
}

static inline int
as_ordered_set(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_ordered_set_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_set_$t$ *ordered_settable_set;
    seagrass_required_true(!as_ordered_settable_set((void *)
            object, &ordered_settable_set));
    return INVOKE_ORDERED_SETTABLE_SET(ordered_settable_set)
        ->as_ordered_set(ordered_settable_set, out);
}

static inline int
as_insertable(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_insertable_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_incremental_set_$t$ *ordered_incremental_set;
    seagrass_required_true(!as_ordered_incremental_set(
            object, &ordered_incremental_set));
    return INVOKE_ORDERED_INCREMENTAL_SET(ordered_incremental_set)
            ->as_insertable(ordered_incremental_set, out);
}

static inline int
as_settable_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_set_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_ordered_settable_set_$t$ *ordered_settable_set;
    seagrass_required_true(!as_ordered_settable_set(
            object, &ordered_settable_set));
    return INVOKE_ORDERED_SETTABLE_SET(ordered_settable_set)
        ->as_settable_set(ordered_settable_set, out);
}

static inline int
as_addable(
        struct butterflyfish_ordered_settable_incremental_set_$t$*const object,
        struct butterflyfish_addable_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_incremental_set_$t$ *incremental_set;
    seagrass_required_true(!as_incremental_set(object, &incremental_set));
    return INVOKE_INCREMENTAL_SET(incremental_set)
            ->as_addable(incremental_set, out);
}

static inline int
as_set(const struct butterflyfish_ordered_settable_incremental_set_$t$
        *const object,
       const struct butterflyfish_set_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_$t$ *settable_set;
    seagrass_required_true(!as_settable_set((void *) object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_set(settable_set, out);
}

static inline int
as_ordered(
        const struct butterflyfish_ordered_settable_incremental_set_$t$ *const
                object,
        const struct butterflyfish_ordered_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_ordered_set_$t$ *ordered_set;
    seagrass_required_true(!as_ordered_set(object, &ordered_set));
    return INVOKE_ORDERED_SET(ordered_set)->as_ordered(ordered_set, out);
}

static inline int
as_settable(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_$t$ **const out) {
    assert(object);
    assert(out);
    struct butterflyfish_settable_set_$t$ *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->as_settable(settable_set, out);
}

static inline int
as_collection(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->as_collection(set, out);
}

static inline int
as_stream(const struct butterflyfish_ordered_settable_incremental_set_$t$
        *const object,
          const struct butterflyfish_stream_$t$ **const out) {
    assert(object);
    assert(out);
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->as_stream(collection, out);
}

#pragma mark stream_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_first(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$*const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->first(stream, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_next(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_stream_$t$ *stream;
    seagrass_required_true(!as_stream(object, &stream));
    return INVOKE_STREAM(stream)->next(stream, item, out);
}

#pragma mark collection_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_count(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        uintmax_t *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->count(collection, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_last(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$*const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->last(collection, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_prev(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$const item,
        const $v$*const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_collection_$t$ *collection;
    seagrass_required_true(!as_collection(object, &collection));
    return INVOKE_COLLECTION(collection)->prev(collection, item, out);
}

#pragma mark settable_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_set_item(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const $v$const item,
        const $v$const value) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_$t$ *settable;
    seagrass_required_true(!as_settable(object, &settable));
    return INVOKE_SETTABLE(settable)->set_item(settable, item, value);
}

#pragma mark set_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_contains(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$const value,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains(set, value, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_contains_all(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_stream_$t$ *const other,
        bool *const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->contains_all(set, other, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_get(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const $v$const value,
        const $v$*const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    const struct butterflyfish_set_$t$ *set;
    seagrass_required_true(!as_set(object, &set));
    return INVOKE_SET(set)->get(set, value, out);
}

#pragma mark settable_set_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const $v$const item,
        const $v$const value) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_settable_set_$t$ *settable_set;
    seagrass_required_true(!as_settable_set(object, &settable_set));
    return INVOKE_SETTABLE_SET(settable_set)->set(settable_set, item, value);
}

#pragma mark addable_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_add(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const $v$const value) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add(addable, value);
}

int butterflyfish_ordered_settable_incremental_set_$t$_add_all(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_addable_$t$ *addable;
    seagrass_required_true(!as_addable(object, &addable));
    return INVOKE_ADDABLE(addable)->add_all(addable, other);
}

#pragma mark insertable_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_insert(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const $v$const item,
        const $v$const value) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!value) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_VALUE_IS_NULL;
    }
    struct butterflyfish_insertable_$t$ *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert(insertable, item, value);
}

int butterflyfish_ordered_settable_incremental_set_$t$_insert_all(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        const $v$const item,
        const struct butterflyfish_stream_$t$ *const other) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!item) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_ITEM_IS_NULL;
    }
    if (!other) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OTHER_IS_NULL;
    }
    struct butterflyfish_insertable_$t$ *insertable;
    seagrass_required_true(!as_insertable(object, &insertable));
    return INVOKE_INSERTABLE(insertable)->insert_all(insertable, item, other);
}

#pragma mark ordered_settable_incremental_set_$t$ -

int butterflyfish_ordered_settable_incremental_set_$t$_as_stream(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_stream_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_stream(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_collection(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_collection_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_collection(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_settable(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_settable(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_ordered(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_ordered_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_set(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_set(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_addable(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_addable_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_addable(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_settable_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_settable_set(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_insertable(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_insertable_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_insertable(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_ordered_set(
        const struct butterflyfish_ordered_settable_incremental_set_$t$
                *const object,
        const struct butterflyfish_ordered_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered_set(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_incremental_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_incremental_set(object, out);
}

int butterflyfish_ordered_settable_incremental_set_$t$_as_ordered_settable_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_ordered_settable_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered_settable_set(object, out);
}

int
butterflyfish_ordered_settable_incremental_set_$t$_as_ordered_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_ordered_incremental_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_ordered_incremental_set(object, out);
}

int
butterflyfish_ordered_settable_incremental_set_$t$_as_settable_incremental_set(
        struct butterflyfish_ordered_settable_incremental_set_$t$ *const object,
        struct butterflyfish_settable_incremental_set_$t$ **const out) {
    if (!object) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OBJECT_IS_NULL;
    }
    if (!out) {
        return
        BUTTERFLYFISH_ORDERED_SETTABLE_INCREMENTAL_SET_$T$_ERROR_OUT_IS_NULL;
    }
    return as_settable_incremental_set(object, out);
}
