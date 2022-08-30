{
    'targets': [
        {
            'target_name': 'jtp',
            'sources': ['jtp.cpp'],
            'include_dirs':[
                './ctp_api_6.6.1_20210406/',
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            # 'cflags!': [ '-fno-exceptions' ],
            # 'cflags_cc!': [ '-fno-exceptions' ],
            # 'defines': [ 'NAPI_CPP_EXCEPTIONS' ],  
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
            'conditions':[
                ['OS=="linux"', {
                    'libraries': [
                        '-L../ctp_api_6.6.1_20210406/linux64/',
                        '-lthostmduserapi_se',
                        '-lthosttraderapi_se',
                    ],
                    'copies':[
                        {
                            'destination': './build/Release/',
                            'files': [
                                './ctp_api_6.6.1_20210406/linux64/libthostmduserapi_se.so',
                                './ctp_api_6.6.1_20210406/linux64/libthosttraderapi_se.so',
                                # './Release/jtp.node',
                            ]
                        }
                    ]
                }],
                ['OS=="win"', {
                    'msvs_settings': {
                        'VCCLCompilerTool': {
                            'DisableSpecificWarnings': ['4819'],
                            # 'AdditionalOptions': ['/EHsc'],
                            # 'ExceptionHandling': 1 ,
                        },
                    },
                    'libraries': [
                        '../ctp_api_6.6.1_20210406/win64/thostmduserapi_se.lib',
                        '../ctp_api_6.6.1_20210406/win64/thosttraderapi_se.lib',
                    ],
                    'copies':[
                        {
                            'destination': './build/Release/',
                            'files': [
                                './ctp_api_6.6.1_20210406/win64/thostmduserapi_se.dll',
                                './ctp_api_6.6.1_20210406/win64/thosttraderapi_se.dll',
                            ]
                        }
                    ]
                }]
            ]
        }
    ]
}
