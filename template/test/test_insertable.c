#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_insertable_$t$ *const insertable_$t$;
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

static int
collection_as_stream(const struct butterflyfish_collection_$t$ *const object,
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
        .as_stream = collection_as_stream,
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
insertable_as_ordered(const struct butterflyfish_insertable_$t$ *const object,
                      const struct butterflyfish_ordered_$t$ **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, insertable_$t$, ordered_$t$);
    return 0;
}

static int
insertable_insert(struct butterflyfish_insertable_$t$ *const object,
                  const $v$const item,
                  const $v$const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

static int
insertable_insert_all(struct butterflyfish_insertable_$t$ *const object,
                      const $v$const item,
                      const struct butterflyfish_stream_$t$ *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_insertable_$t$ insertable_$t$ = {
        .as_ordered = insertable_as_ordered,
        .insert = insertable_insert,
        .insert_all = insertable_insert_all,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_$t$);
    const struct butterflyfish_stream_$t$ *out;
    assert_int_equal(butterflyfish_insertable_$t$_as_stream(
            (const struct butterflyfish_insertable_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_$t$);
    const struct butterflyfish_collection_$t$ *out;
    assert_int_equal(butterflyfish_insertable_$t$_as_collection(
            (const struct butterflyfish_insertable_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_$t$);
    const struct butterflyfish_ordered_$t$ *out;
    assert_int_equal(butterflyfish_insertable_$t$_as_ordered(
            (const struct butterflyfish_insertable_$t$ *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_count(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_count((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_insertable_$t$_count(
            (const struct butterflyfish_insertable_$t$ *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_first(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_first((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_ordered_is_empty(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_$T$_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_insertable_$t$_first(
                    (const struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_INSERTABLE_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_last(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_last((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_ordered_is_empty(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_insertable_$t$_last(
                    (const struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_INSERTABLE_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_insertable_$t$_next(
                    (const struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_$T$_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_insertable_$t$_prev(
                    (const struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_END_OF_SEQUENCE);
}

static void check_insert_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_insert_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_insert_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_NULL);
}

static void check_insert_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_insertable_$t$_insert(
                    (struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_VALUE_IS_INVALID);
}

static void check_insert_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_insertable_$t$_insert(
                    (struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OBJECT_IS_NULL);
}

static void check_insert_all_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_ITEM_IS_NULL);
}

static void check_insert_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_$t$_insert_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_OTHER_IS_NULL);
}

static void check_insert_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .insertable_$t$ = &insertable_$t$,
            .ordered_$t$ = &ordered_$t$,
            .collection_$t$ = &collection_$t$,
            .stream_$t$ = &stream_$t$
    };
    expect_function_call(insertable_insert_all);
    will_return(insertable_insert_all,
                BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_insertable_$t$_insert_all(
                    (struct butterflyfish_insertable_$t$ *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_$T$_ERROR_MEMORY_ALLOCATION_FAILED);
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
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_ordered_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_ordered_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_insert_error_on_object_is_null),
            cmocka_unit_test(check_insert_error_on_item_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_null),
            cmocka_unit_test(check_insert_error_on_value_is_invalid),
            cmocka_unit_test(check_insert_error_on_memory_allocation_failed),
            cmocka_unit_test(check_insert_all_error_on_object_is_null),
            cmocka_unit_test(check_insert_all_error_on_item_is_null),
            cmocka_unit_test(check_insert_all_error_on_other_is_null),
            cmocka_unit_test(check_insert_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
