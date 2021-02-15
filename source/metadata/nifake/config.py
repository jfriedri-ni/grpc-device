# -*- coding: utf-8 -*-
# This file is generated from NI-FAKE API metadata version 1.2.0d9
config = {
    'api_version': '1.2.0d9',
    'c_function_prefix': 'niFake_',
    'service_class_prefix': 'NiFake',
    'grpc_package': 'ni.fake.grpc',
    'java_package': 'com.ni.fake.grpc',
    'csharp_namespace': 'NationalInstruments.Fake.Grpc',
    'close_function': 'close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        'task': 'acquisition'
    },
    'custom_types': [
        {
            'name': 'CustomStruct',
            'fields': [
                {
                    'type': 'ViInt32',
                    'name': 'structInt'
                },
                {
                    'type': 'ViReal64',
                    'name': 'structDouble'
                }
            ]
        }
    ],
    'driver_name': 'NI-FAKE',
    'enum_whitelist_suffix': [
        '_POINT_FIVE'
    ],
    'extra_errors_used': [
        'InvalidRepeatedCapabilityError',
        'SelfTestError'
    ],
    'init_function': 'InitWithOptions',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nifake',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nifake_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nifake_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '2.0',
    'module_name': 'nifake',
    'repeated_capabilities': [
        {
            'prefix': '',
            'python_name': 'channels'
        },
        {
            'prefix': 'site',
            'python_name': 'sites',
        },
    ],
    'session_class_description': 'An NI-FAKE session to a fake MI driver whose sole purpose is to test nimi-python code generation',
    'session_handle_parameter_name': 'vi',
    'uses_nitclk': True,
}
