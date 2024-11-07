#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

struct object {
    const struct butterflyfish_collection_i_i *const collection_i_i;
    const struct butterflyfish_stream_i_i *const stream_i_i;
};

static int stream_first(const struct butterflyfish_stream_i_i *const object,
                        const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int stream_next(const struct butterflyfish_stream_i_i *const object,
                       const struct butterflyfish_map_i_i_entry *const item,
                       const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

const struct butterflyfish_stream_i_i stream_i_i = {
        .first = stream_first,
        .next = stream_next
};

static int as_stream(const struct butterflyfish_collection_i_i *const object,
                     const struct butterflyfish_stream_i_i **const out) {
    assert_non_null(object);
    assert_non_null(out);
    *out = butterflyfish_cast(object, struct object, collection_i_i,
            stream_i_i);
    return 0;
}

static int
collection_last(const struct butterflyfish_collection_i_i *const object,
                const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static int
collection_prev(const struct butterflyfish_collection_i_i *const object,
                const struct butterflyfish_map_i_i_entry *const item,
                const struct butterflyfish_map_i_i_entry **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static int
collection_count(const struct butterflyfish_collection_i_i *const object,
                 uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

const struct butterflyfish_collection_i_i collection_i_i = {
        .as_stream = as_stream,
        .last = collection_last,
        .prev = collection_prev,
        .count = collection_count,
};

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    const void *check = (char *) &instance
            + offsetof(struct object, stream_i_i);
    const struct butterflyfish_stream_i_i *out;
    assert_int_equal(butterflyfish_collection_i_i_as_stream(
            (struct butterflyfish_collection_i_i *) &instance, &out), 0);
    assert_ptr_equal(out, check);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_count((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_count);
    const uintmax_t check = abs(rand());
    will_return(collection_count, check);
    uintmax_t out;
    assert_int_equal(butterflyfish_collection_i_i_count(
            (const struct butterflyfish_collection_i_i *) &instance, &out), 0);
    assert_int_equal(out, check);
}

static void check_first_error_on_collection_is_empty(void **state) {
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_first);
    will_return(stream_first,
                BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_i_first(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_first((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_last((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_collection_is_empty(void **state) {
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_last);
    will_return(collection_last,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_i_last(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(stream_next);
    will_return(stream_next,
                BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_i_next(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_i_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct object instance = {
            .collection_i_i = &collection_i_i,
            .stream_i_i = &stream_i_i
    };
    expect_function_call(collection_prev);
    will_return(collection_prev,
                BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_i_prev(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_collection_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
