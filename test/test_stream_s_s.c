#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_s_s_first(NULL, (void *) 1),
            BUTTERFLYFISH_STREAM_S_S_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_s_s_first((void *) 1, NULL),
            BUTTERFLYFISH_STREAM_S_S_ERROR_OUT_IS_NULL);
}

static int
first_emit_error(const void *const object,
                 struct butterflyfish_map_entry_s_s **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_stream_s_s stream_s_s = {
            .first = first_emit_error
    };
    struct object {
        const struct butterflyfish_stream_s_s *stream_s_s;
    };
    struct object instance = {
            .stream_s_s = &stream_s_s
    };
    expect_function_call(first_emit_error);
    will_return(first_emit_error,
                BUTTERFLYFISH_STREAM_S_S_ERROR_STREAM_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_s_s_first(
                    (const struct butterflyfish_stream_s_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_S_ERROR_STREAM_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_s_s_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_STREAM_S_S_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_s_s_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_STREAM_S_S_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_stream_s_s_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_STREAM_S_S_ERROR_OUT_IS_NULL);
}

static int
next_emit_error(const void *const object,
                const struct butterflyfish_map_entry_s_s *const item,
                struct butterflyfish_map_entry_s_s **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_stream_s_s stream_s_s = {
            .next = next_emit_error
    };
    struct object {
        const struct butterflyfish_stream_s_s *stream_s_s;
    };
    struct object instance = {
            .stream_s_s = &stream_s_s
    };
    expect_function_call(next_emit_error);
    will_return(next_emit_error,
                BUTTERFLYFISH_STREAM_S_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_s_s_next(
                    (const struct butterflyfish_stream_s_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_S_ERROR_END_OF_SEQUENCE);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_stream_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
