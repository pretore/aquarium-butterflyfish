#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>
#include <test/cmocka.h>

struct object {
    const struct butterflyfish_insertable_i *const insertable_i;
    const struct butterflyfish_ordered_i *const ordered_i;
    const struct butterflyfish_collection_i *const collection_i;
    const struct butterflyfish_stream_i *const stream_i;
};

static int stream_first(const struct butterflyfish_stream_i *const object,
                        const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_i *const object,
                       const struct sea_turtle_integer *const item,
                       const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_i stream_i = {
        .first = stream_first,
        .next = stream_next
};

static int
collection_as_stream(const struct butterflyfish_collection_i *const object,
                     const struct butterflyfish_stream_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i, stream_i);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_i *const object,
                const struct sea_turtle_integer *const item,
                const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_i *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i collection_i = {
        .as_stream = collection_as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static int
ordered_as_collection(const struct butterflyfish_ordered_i *const object,
                      const struct butterflyfish_collection_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, ordered_i, collection_i);
    return 0;
}

const struct butterflyfish_ordered_i ordered_i = {
        .as_collection = ordered_as_collection,
};

static int
insertable_as_ordered(const struct butterflyfish_insertable_i *const object,
                      const struct butterflyfish_ordered_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, insertable_i, ordered_i);
    return 0;
}

static int
insertable_insert(struct butterflyfish_insertable_i *const object,
                  const struct sea_turtle_integer *const item,
                  const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(value);
    return mock();
}

static int
insertable_insert_all(struct butterflyfish_insertable_i *const object,
                      const struct sea_turtle_integer *const item,
                      const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(other);
    return mock();
}

const struct butterflyfish_insertable_i insertable_i = {
        .as_ordered = insertable_as_ordered,
        .insert = insertable_insert,
        .insert_all = insertable_insert_all,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance + offsetof(struct object, stream_i);
    const struct butterflyfish_stream_i *out;
    assert_int_equal(butterflyfish_insertable_i_as_stream(
            (const struct butterflyfish_insertable_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, collection_i);
    const struct butterflyfish_collection_i *out;
    assert_int_equal(butterflyfish_insertable_i_as_collection(
            (const struct butterflyfish_insertable_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_as_ordered_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_ordered(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_as_ordered((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_as_ordered(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, ordered_i);
    const struct butterflyfish_ordered_i *out;
    assert_int_equal(butterflyfish_insertable_i_as_ordered(
            (const struct butterflyfish_insertable_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_count((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_insertable_i_count(
            (const struct butterflyfish_insertable_i *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_first((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_ordered_is_empty(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_insertable_i_first(
                    (const struct butterflyfish_insertable_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_INSERTABLE_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_last((void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_ordered_is_empty(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_insertable_i_last(
                    (const struct butterflyfish_insertable_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_INSERTABLE_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_insertable_i_next(
                    (const struct butterflyfish_insertable_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_insertable_i_prev(
                    (const struct butterflyfish_insertable_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_END_OF_SEQUENCE);
}

static void check_insert_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_IS_NULL);
}

static void check_insert_error_on_value_is_invalid(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_insertable_i_insert(
                    (struct butterflyfish_insertable_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_VALUE_IS_INVALID);
}

static void check_insert_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert);
    will_return(insertable_insert,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_insertable_i_insert(
                    (struct butterflyfish_insertable_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_insert_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OBJECT_IS_NULL);
}

static void check_insert_all_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_ITEM_IS_NULL);
}

static void check_insert_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_insertable_i_insert_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_OTHER_IS_NULL);
}

static void check_insert_all_error_on_memory_allocation_failed(void **state) {
    const struct object instance = {
            .insertable_i = &insertable_i,
            .ordered_i = &ordered_i,
            .collection_i = &collection_i,
            .stream_i = &stream_i
    };
    expect_function_call(insertable_insert_all);
    will_return(insertable_insert_all,
                BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_insertable_i_insert_all(
                    (struct butterflyfish_insertable_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_INSERTABLE_I_ERROR_MEMORY_ALLOCATION_FAILED);
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
