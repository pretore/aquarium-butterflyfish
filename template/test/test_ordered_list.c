#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_ordered_list_$t$ *const ordered_list_$t$;
    const struct butterflyfish_list_$t$ *const list_$t$;
    const struct butterflyfish_ordered_$t$ *const ordered_$t$;
    const struct butterflyfish_collection_$t$ *const collection_$t$;
    const struct butterflyfish_stream_$t$ *const stream_$t$;
};

static int stream_first(const struct butterflyfish_stream_$t$ *const object,
                        const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_$t$ *const object,
                       const $v$const item,
                       const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_$t$ stream_$t$ = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_$t$ *const object,
                     const struct butterflyfish_stream_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_$t$, stream_$t$);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_$t$ *const object,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_$t$ *const object,
                const $v$const item,
                const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_$t$ *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_$t$ collection_$t$ = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
ordered_as_collection(const struct butterflyfish_ordered_$t$ *const object,
                      const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_$t$, collection_$t$);
    return 0;
}

const struct butterflyfish_ordered_$t$ ordered_$t$ = {
        .as_collection = ordered_as_collection,
};

static int
list_as_collection(const struct butterflyfish_list_$t$ *const object,
                   const struct butterflyfish_collection_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, list_$t$, collection_$t$);
    return 0;
}

static int list_get(const struct butterflyfish_list_$t$ *const object,
                    const uintmax_t at,
                    const $v$*const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int list_at(const struct butterflyfish_list_$t$ *const object,
                   const $v$const item,
                   uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_list_$t$ list_$t$ = {
        .as_collection = list_as_collection,
        .get = list_get,
        .at = list_at
};

static int
ordered_list_as_list(const struct butterflyfish_ordered_list_$t$ *const object,
                     const struct butterflyfish_list_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_list_$t$, list_$t$);
    return 0;
}

static int
ordered_list_as_ordered(
        const struct butterflyfish_ordered_list_$t$ *const object,
        const struct butterflyfish_ordered_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_list_$t$,
            ordered_$t$);
    return 0;
}

const struct butterflyfish_ordered_list_$t$ ordered_list_$t$ = {
        .as_list = ordered_list_as_list,
        .as_ordered = ordered_list_as_ordered
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_$t$);
    const struct butterflyfish_stream_$t$ *out;
    assert_int_equal(butterflyfish_ordered_list_$t$_as_stream(
            (const struct butterflyfish_ordered_list_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_ordered_list_$t$_as_collection(
            (const struct butterflyfish_ordered_list_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, ordered_$t$);
    const struct butterflyfish_ordered_$t$ *out;
    assert_int_equal(butterflyfish_ordered_list_$t$_as_ordered(
            (const struct butterflyfish_ordered_list_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_list(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_as_list((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_list(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, list_$t$);
    const struct butterflyfish_list_$t$ *out;
    assert_int_equal(butterflyfish_ordered_list_$t$_as_list(
            (struct butterflyfish_ordered_list_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_ordered_as_collection(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
                        + offsetof(struct object, collection_$t$);
    const struct butterflyfish_ordered_$t$ *as;
    assert_int_equal(butterflyfish_ordered_list_$t$_as_ordered(
            (struct butterflyfish_ordered_list_$t$ *) &instance, &as), 0);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_ordered_$t$_as_collection(as, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_ordered_list_$t$_count(
            (const struct butterflyfish_ordered_list_$t$ *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_first(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_LIST_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_list_is_empty(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_last(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_LIST_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_next(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_prev(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(list_get);
    will_return(list_get,
                BUTTERFLYFISH_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_get(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_list_$t$_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_OUT_IS_NULL);
}

static void check_get_error_on_item_not_found(void **state) {
    const struct object instance = {
            .ordered_list_$t$ = &ordered_list_$t$,
            .list_$t$ = &list_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(list_at);
    will_return(list_at,
                BUTTERFLYFISH_LIST_$T$_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_list_$t$_at(
                    (const struct butterflyfish_ordered_list_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_LIST_$T$_ERROR_ITEM_NOT_FOUND);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_ordered_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered),
            cmocka_unit_test(check_as_list_error_on_object_is_null),
            cmocka_unit_test(check_as_list_error_on_out_is_null),
            cmocka_unit_test(check_as_list),
            cmocka_unit_test(check_ordered_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_list_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_list_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_item_not_found),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
