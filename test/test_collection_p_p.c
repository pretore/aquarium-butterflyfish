#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_count(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_count((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              const struct butterflyfish_map_entry_p_p **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .stream_p_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_p_first(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .stream_p_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_p_p_first(
                    (const struct butterflyfish_stream_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_P_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_first(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_first((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_last(NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_last((void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_p_last(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_p_p *const item,
              const struct butterflyfish_map_entry_p_p **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .stream_p_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_p_next(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .stream_p_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_p_p_next(
                    (const struct butterflyfish_stream_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_P_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_collection_p_p_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_collection_p_p collection_p_p = {
            .prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_collection_p_p *collection_p_p;
    };
    struct object instance = {
            .collection_p_p = &collection_p_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_p_prev(
                    (const struct butterflyfish_collection_p_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
