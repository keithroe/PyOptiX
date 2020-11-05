
#include <pybind11/pybind11.h>
#include <optix.h>

#include <memory>
#include <stdexcept>


namespace py = pybind11;
    
PYBIND11_MAKE_OPAQUE( OptixModule );
PYBIND11_MAKE_OPAQUE( OptixModule_t );

#define PYOPTIX_CHECK( call )                                                  \
    do                                                                         \
    {                                                                          \
        OptixResult res = call;                                                \
        if( res != OPTIX_SUCCESS )                                             \
            throw std::runtime_error( optixGetErrorString( res )  );           \
    } while( 0 )

namespace pyoptix
{
// Opaque type struct wrappers

struct DeviceContext
{
    OptixDeviceContext deviceContext;
};

struct Module
{
    OptixModule module;
};

struct ProgramGroup
{
    OptixProgramGroup programGroup;
};

struct Pipeline
{
    OptixPipeline pipeline;
};

struct Denoiser
{
    OptixDenoiser denoiser;
};


// Error checking api func wrappers

const char* getErrorName( 
       OptixResult result
    )
{
    return optixGetErrorName( result );
}
 
const char* getErrorString( 
       OptixResult result
    )
{
    return optixGetErrorString( result );
}
 
void deviceContextCreate( 
       CUcontext fromContext,
       const OptixDeviceContextOptions* options,
       OptixDeviceContext* context
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextCreate(
            fromContext,
            options,
            context
        )
    );
}
 
void deviceContextDestroy( 
       OptixDeviceContext context
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextDestroy(
            context
        )
    );
}
 
void deviceContextGetProperty( 
       OptixDeviceContext context,
       OptixDeviceProperty property,
       void* value,
       size_t sizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextGetProperty(
            context,
            property,
            value,
            sizeInBytes
        )
    );
}
 
void deviceContextSetLogCallback( 
       OptixDeviceContext context,
       OptixLogCallback   callbackFunction,
       void*              callbackData,
       unsigned int       callbackLevel
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextSetLogCallback(
            context,
            callbackFunction,
            callbackData,
            callbackLevel
        )
    );
}
 
void deviceContextSetCacheEnabled( 
       OptixDeviceContext context,
       int                enabled
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextSetCacheEnabled(
            context,
            enabled
        )
    );
}
 
void deviceContextSetCacheLocation( 
       OptixDeviceContext context,
       const char* location
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextSetCacheLocation(
            context,
            location
        )
    );
}
 
void deviceContextSetCacheDatabaseSizes( 
       OptixDeviceContext context,
       size_t lowWaterMark,
       size_t highWaterMark
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextSetCacheDatabaseSizes(
            context,
            lowWaterMark,
            highWaterMark
        )
    );
}
 
void deviceContextGetCacheEnabled( 
       OptixDeviceContext context,
       int* enabled
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextGetCacheEnabled(
            context,
            enabled
        )
    );
}
 
void deviceContextGetCacheLocation( 
       OptixDeviceContext context,
       char* location,
       size_t locationSize
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextGetCacheLocation(
            context,
            location,
            locationSize
        )
    );
}
 
void deviceContextGetCacheDatabaseSizes( 
       OptixDeviceContext context,
       size_t* lowWaterMark,
       size_t* highWaterMark
    )
{
    PYOPTIX_CHECK( 
        optixDeviceContextGetCacheDatabaseSizes(
            context,
            lowWaterMark,
            highWaterMark
        )
    );
}
 
void pipelineCreate( 
       OptixDeviceContext                 context,
       const OptixPipelineCompileOptions* pipelineCompileOptions,
       const OptixPipelineLinkOptions*    pipelineLinkOptions,
       const OptixProgramGroup*           programGroups,
       unsigned int                       numProgramGroups,
       char*                              logString,
       size_t*                            logStringSize,
       OptixPipeline*                     pipeline
    )
{
    PYOPTIX_CHECK( 
        optixPipelineCreate(
            context,
            pipelineCompileOptions,
            pipelineLinkOptions,
            programGroups,
            numProgramGroups,
            logString,
            logStringSize,
            pipeline
        )
    );
}
 
void pipelineDestroy( 
       OptixPipeline pipeline
    )
{
    PYOPTIX_CHECK( 
        optixPipelineDestroy(
            pipeline
        )
    );
}
 
void pipelineSetStackSize( 
       OptixPipeline pipeline,
       unsigned int  directCallableStackSizeFromTraversal,
       unsigned int  directCallableStackSizeFromState,
       unsigned int  continuationStackSize,
       unsigned int  maxTraversableGraphDepth
    )
{
    PYOPTIX_CHECK( 
        optixPipelineSetStackSize(
            pipeline,
            directCallableStackSizeFromTraversal,
            directCallableStackSizeFromState,
            continuationStackSize,
            maxTraversableGraphDepth
        )
    );
}
 
void moduleCreateFromPTX( 
       OptixDeviceContext                 context,
       const OptixModuleCompileOptions*   moduleCompileOptions,
       const OptixPipelineCompileOptions* pipelineCompileOptions,
       const char*                        PTX,
       size_t                             PTXsize,
       char*                              logString,
       size_t*                            logStringSize,
       OptixModule*                       module
    )
{
    PYOPTIX_CHECK( 
        optixModuleCreateFromPTX(
            context,
            moduleCompileOptions,
            pipelineCompileOptions,
            PTX,
            PTXsize,
            logString,
            logStringSize,
            module
        )
    );
}
 
void moduleDestroy( 
       OptixModule module
    )
{
    PYOPTIX_CHECK( 
        optixModuleDestroy(
            module
        )
    );
}
 
void builtinISModuleGet( 
       OptixDeviceContext                 context,
       const OptixModuleCompileOptions*   moduleCompileOptions,
       const OptixPipelineCompileOptions* pipelineCompileOptions,
       const OptixBuiltinISOptions*       builtinISOptions,
       OptixModule*                       builtinModule
    )
{
    PYOPTIX_CHECK( 
        optixBuiltinISModuleGet(
            context,
            moduleCompileOptions,
            pipelineCompileOptions,
            builtinISOptions,
            builtinModule
        )
    );
}
 
void programGroupGetStackSize( 
       OptixProgramGroup programGroup,
       OptixStackSizes* stackSizes
    )
{
    PYOPTIX_CHECK( 
        optixProgramGroupGetStackSize(
            programGroup,
            stackSizes
        )
    );
}
 
void programGroupCreate( 
       OptixDeviceContext              context,
       const OptixProgramGroupDesc*    programDescriptions,
       unsigned int                    numProgramGroups,
       const OptixProgramGroupOptions* options,
       char*                           logString,
       size_t*                         logStringSize,
       OptixProgramGroup*              programGroups
    )
{
    PYOPTIX_CHECK( 
        optixProgramGroupCreate(
            context,
            programDescriptions,
            numProgramGroups,
            options,
            logString,
            logStringSize,
            programGroups
        )
    );
}
 
void programGroupDestroy( 
       OptixProgramGroup programGroup
    )
{
    PYOPTIX_CHECK( 
        optixProgramGroupDestroy(
            programGroup
        )
    );
}
 
void launch( 
       OptixPipeline                  pipeline,
       CUstream                       stream,
       CUdeviceptr                    pipelineParams,
       size_t                         pipelineParamsSize,
       const OptixShaderBindingTable* sbt,
       unsigned int                   width,
       unsigned int                   height,
       unsigned int                   depth
    )
{
    PYOPTIX_CHECK( 
        optixLaunch(
            pipeline,
            stream,
            pipelineParams,
            pipelineParamsSize,
            sbt,
            width,
            height,
            depth
        )
    );
}
 
void sbtRecordPackHeader( 
       OptixProgramGroup programGroup,
       void* sbtRecordHeaderHostPointer
    )
{
    PYOPTIX_CHECK( 
        optixSbtRecordPackHeader(
            programGroup,
            sbtRecordHeaderHostPointer
        )
    );
}
 
void accelComputeMemoryUsage( 
       OptixDeviceContext            context,
       const OptixAccelBuildOptions* accelOptions,
       const OptixBuildInput*        buildInputs,
       unsigned int                  numBuildInputs,
       OptixAccelBufferSizes*        bufferSizes
    )
{
    PYOPTIX_CHECK( 
        optixAccelComputeMemoryUsage(
            context,
            accelOptions,
            buildInputs,
            numBuildInputs,
            bufferSizes
        )
    );
}
 
void accelBuild( 
       OptixDeviceContext            context,
       CUstream                      stream,
       const OptixAccelBuildOptions* accelOptions,
       const OptixBuildInput*        buildInputs,
       unsigned int                  numBuildInputs,
       CUdeviceptr                   tempBuffer,
       size_t                        tempBufferSizeInBytes,
       CUdeviceptr                   outputBuffer,
       size_t                        outputBufferSizeInBytes,
       OptixTraversableHandle*       outputHandle,
       const OptixAccelEmitDesc*     emittedProperties,
       unsigned int                  numEmittedProperties
    )
{
    PYOPTIX_CHECK( 
        optixAccelBuild(
            context,
            stream,
            accelOptions,
            buildInputs,
            numBuildInputs,
            tempBuffer,
            tempBufferSizeInBytes,
            outputBuffer,
            outputBufferSizeInBytes,
            outputHandle,
            emittedProperties,
            numEmittedProperties
        )
    );
}
 
void accelGetRelocationInfo( 
       OptixDeviceContext context,
       OptixTraversableHandle handle,
       OptixAccelRelocationInfo* info
    )
{
    PYOPTIX_CHECK( 
        optixAccelGetRelocationInfo(
            context,
            handle,
            info
        )
    );
}
 
void accelCheckRelocationCompatibility( 
       OptixDeviceContext context,
       const OptixAccelRelocationInfo* info,
       int* compatible
    )
{
    PYOPTIX_CHECK( 
        optixAccelCheckRelocationCompatibility(
            context,
            info,
            compatible
        )
    );
}
 
void accelRelocate( 
       OptixDeviceContext              context,
       CUstream                        stream,
       const OptixAccelRelocationInfo* info,
       CUdeviceptr                     instanceTraversableHandles,
       size_t                          numInstanceTraversableHandles,
       CUdeviceptr                     targetAccel,
       size_t                          targetAccelSizeInBytes,
       OptixTraversableHandle*         targetHandle
    )
{
    PYOPTIX_CHECK( 
        optixAccelRelocate(
            context,
            stream,
            info,
            instanceTraversableHandles,
            numInstanceTraversableHandles,
            targetAccel,
            targetAccelSizeInBytes,
            targetHandle
        )
    );
}
 
void accelCompact( 
       OptixDeviceContext      context,
       CUstream                stream,
       OptixTraversableHandle  inputHandle,
       CUdeviceptr             outputBuffer,
       size_t                  outputBufferSizeInBytes,
       OptixTraversableHandle* outputHandle
    )
{
    PYOPTIX_CHECK( 
        optixAccelCompact(
            context,
            stream,
            inputHandle,
            outputBuffer,
            outputBufferSizeInBytes,
            outputHandle
        )
    );
}
 
void convertPointerToTraversableHandle( 
       OptixDeviceContext      onDevice,
       CUdeviceptr             pointer,
       OptixTraversableType    traversableType,
       OptixTraversableHandle* traversableHandle
    )
{
    PYOPTIX_CHECK( 
        optixConvertPointerToTraversableHandle(
            onDevice,
            pointer,
            traversableType,
            traversableHandle
        )
    );
}
 
void denoiserCreate( 
       OptixDeviceContext context,
       const OptixDenoiserOptions* options,
       OptixDenoiser* denoiser
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserCreate(
            context,
            options,
            denoiser
        )
    );
}
 
void denoiserSetModel( 
       OptixDenoiser denoiser,
       OptixDenoiserModelKind kind,
       void* data,
       size_t sizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserSetModel(
            denoiser,
            kind,
            data,
            sizeInBytes
        )
    );
}
 
void denoiserDestroy( 
       OptixDenoiser denoiser
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserDestroy(
            denoiser
        )
    );
}
 
void denoiserComputeMemoryResources( 
       const OptixDenoiser denoiser,
       unsigned int        outputWidth,
       unsigned int        outputHeight,
       OptixDenoiserSizes* returnSizes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserComputeMemoryResources(
            denoiser,
            outputWidth,
            outputHeight,
            returnSizes
        )
    );
}
 
void denoiserSetup( 
       OptixDenoiser denoiser,
       CUstream      stream,
       unsigned int  inputWidth,
       unsigned int  inputHeight,
       CUdeviceptr   denoiserState,
       size_t        denoiserStateSizeInBytes,
       CUdeviceptr   scratch,
       size_t        scratchSizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserSetup(
            denoiser,
            stream,
            inputWidth,
            inputHeight,
            denoiserState,
            denoiserStateSizeInBytes,
            scratch,
            scratchSizeInBytes
        )
    );
}
 
void denoiserInvoke( 
       OptixDenoiser              denoiser,
       CUstream                   stream,
       const OptixDenoiserParams* params,
       CUdeviceptr                denoiserState,
       size_t                     denoiserStateSizeInBytes,
       const OptixImage2D*        inputLayers,
       unsigned int               numInputLayers,
       unsigned int               inputOffsetX,
       unsigned int               inputOffsetY,
       const OptixImage2D*        outputLayer,
       CUdeviceptr                scratch,
       size_t                     scratchSizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserInvoke(
            denoiser,
            stream,
            params,
            denoiserState,
            denoiserStateSizeInBytes,
            inputLayers,
            numInputLayers,
            inputOffsetX,
            inputOffsetY,
            outputLayer,
            scratch,
            scratchSizeInBytes
        )
    );
}
 
void denoiserComputeIntensity( 
       OptixDenoiser       denoiser,
       CUstream            stream,
       const OptixImage2D* inputImage,
       CUdeviceptr         outputIntensity,
       CUdeviceptr         scratch,
       size_t              scratchSizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserComputeIntensity(
            denoiser,
            stream,
            inputImage,
            outputIntensity,
            scratch,
            scratchSizeInBytes
        )
    );
}
 
void denoiserComputeAverageColor( 
       OptixDenoiser       denoiser,
       CUstream            stream,
       const OptixImage2D* inputImage,
       CUdeviceptr         outputAverageColor,
       CUdeviceptr         scratch,
       size_t              scratchSizeInBytes
    )
{
    PYOPTIX_CHECK( 
        optixDenoiserComputeAverageColor(
            denoiser,
            stream,
            inputImage,
            outputAverageColor,
            scratch,
            scratchSizeInBytes
        )
    );
}


} // end namespace pyoptix

PYBIND11_MODULE( optix, m ) 
{
    m.doc() = R"pbdoc(
        OptiX API 
        -----------------------

        .. currentmodule:: optix

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    //---------------------------------------------------------------------------
    //
    // Module methods 
    //
    //---------------------------------------------------------------------------
    /*
    m.def( "getErrorName", &pyoptix::GetErrorName );
    m.def( "getErrorString", &pyoptix::GetErrorString );
    m.def( "launch", &pyoptix::Launch );
    m.def( "sbtRecordPackHeader", &pyoptix::SbtRecordPackHeader );
    m.def( "convertPointerToTraversableHandle", &pyoptix::ConvertPointerToTraversableHandle );
    */

    
    //---------------------------------------------------------------------------
    //
    // Enumerations 
    //
    //---------------------------------------------------------------------------

    py::enum_<OptixResult>(m, "Result")
        .value( "SUCCESS", OPTIX_SUCCESS )
        .value( "ERROR_INVALID_VALUE", OPTIX_ERROR_INVALID_VALUE )
        .value( "ERROR_HOST_OUT_OF_MEMORY", OPTIX_ERROR_HOST_OUT_OF_MEMORY )
        .value( "ERROR_INVALID_OPERATION", OPTIX_ERROR_INVALID_OPERATION )
        .value( "ERROR_FILE_IO_ERROR", OPTIX_ERROR_FILE_IO_ERROR )
        .value( "ERROR_INVALID_FILE_FORMAT", OPTIX_ERROR_INVALID_FILE_FORMAT )
        .value( "ERROR_DISK_CACHE_INVALID_PATH", OPTIX_ERROR_DISK_CACHE_INVALID_PATH )
        .value( "ERROR_DISK_CACHE_PERMISSION_ERROR", OPTIX_ERROR_DISK_CACHE_PERMISSION_ERROR )
        .value( "ERROR_DISK_CACHE_DATABASE_ERROR", OPTIX_ERROR_DISK_CACHE_DATABASE_ERROR )
        .value( "ERROR_DISK_CACHE_INVALID_DATA", OPTIX_ERROR_DISK_CACHE_INVALID_DATA )
        .value( "ERROR_LAUNCH_FAILURE", OPTIX_ERROR_LAUNCH_FAILURE )
        .value( "ERROR_INVALID_DEVICE_CONTEXT", OPTIX_ERROR_INVALID_DEVICE_CONTEXT )
        .value( "ERROR_CUDA_NOT_INITIALIZED", OPTIX_ERROR_CUDA_NOT_INITIALIZED )
        .value( "ERROR_VALIDATION_FAILURE", OPTIX_ERROR_VALIDATION_FAILURE )
        .value( "ERROR_INVALID_PTX", OPTIX_ERROR_INVALID_PTX )
        .value( "ERROR_INVALID_LAUNCH_PARAMETER", OPTIX_ERROR_INVALID_LAUNCH_PARAMETER )
        .value( "ERROR_INVALID_PAYLOAD_ACCESS", OPTIX_ERROR_INVALID_PAYLOAD_ACCESS )
        .value( "ERROR_INVALID_ATTRIBUTE_ACCESS", OPTIX_ERROR_INVALID_ATTRIBUTE_ACCESS )
        .value( "ERROR_INVALID_FUNCTION_USE", OPTIX_ERROR_INVALID_FUNCTION_USE )
        .value( "ERROR_INVALID_FUNCTION_ARGUMENTS", OPTIX_ERROR_INVALID_FUNCTION_ARGUMENTS )
        .value( "ERROR_PIPELINE_OUT_OF_CONSTANT_MEMORY", OPTIX_ERROR_PIPELINE_OUT_OF_CONSTANT_MEMORY )
        .value( "ERROR_PIPELINE_LINK_ERROR", OPTIX_ERROR_PIPELINE_LINK_ERROR )
        .value( "ERROR_INTERNAL_COMPILER_ERROR", OPTIX_ERROR_INTERNAL_COMPILER_ERROR )
        .value( "ERROR_DENOISER_MODEL_NOT_SET", OPTIX_ERROR_DENOISER_MODEL_NOT_SET )
        .value( "ERROR_DENOISER_NOT_INITIALIZED", OPTIX_ERROR_DENOISER_NOT_INITIALIZED )
        .value( "ERROR_ACCEL_NOT_COMPATIBLE", OPTIX_ERROR_ACCEL_NOT_COMPATIBLE )
        .value( "ERROR_NOT_SUPPORTED", OPTIX_ERROR_NOT_SUPPORTED )
        .value( "ERROR_UNSUPPORTED_ABI_VERSION", OPTIX_ERROR_UNSUPPORTED_ABI_VERSION )
        .value( "ERROR_FUNCTION_TABLE_SIZE_MISMATCH", OPTIX_ERROR_FUNCTION_TABLE_SIZE_MISMATCH )
        .value( "ERROR_INVALID_ENTRY_FUNCTION_OPTIONS", OPTIX_ERROR_INVALID_ENTRY_FUNCTION_OPTIONS )
        .value( "ERROR_LIBRARY_NOT_FOUND", OPTIX_ERROR_LIBRARY_NOT_FOUND )
        .value( "ERROR_ENTRY_SYMBOL_NOT_FOUND", OPTIX_ERROR_ENTRY_SYMBOL_NOT_FOUND )
        .value( "ERROR_LIBRARY_UNLOAD_FAILURE", OPTIX_ERROR_LIBRARY_UNLOAD_FAILURE )
        .value( "ERROR_CUDA_ERROR", OPTIX_ERROR_CUDA_ERROR )
        .value( "ERROR_INTERNAL_ERROR", OPTIX_ERROR_INTERNAL_ERROR )
        .value( "ERROR_UNKNOWN", OPTIX_ERROR_UNKNOWN )
        .export_values();

    py::enum_<OptixDeviceProperty>(m, "DeviceProperty")
        .value( "DEVICE_PROPERTY_LIMIT_MAX_TRACE_DEPTH", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_TRACE_DEPTH )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_TRAVERSABLE_GRAPH_DEPTH", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_TRAVERSABLE_GRAPH_DEPTH )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_PRIMITIVES_PER_GAS", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_PRIMITIVES_PER_GAS )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_INSTANCES_PER_IAS", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_INSTANCES_PER_IAS )
        .value( "DEVICE_PROPERTY_RTCORE_VERSION", OPTIX_DEVICE_PROPERTY_RTCORE_VERSION )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_INSTANCE_ID", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_INSTANCE_ID )
        .value( "DEVICE_PROPERTY_LIMIT_NUM_BITS_INSTANCE_VISIBILITY_MASK", OPTIX_DEVICE_PROPERTY_LIMIT_NUM_BITS_INSTANCE_VISIBILITY_MASK )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_SBT_RECORDS_PER_GAS", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_SBT_RECORDS_PER_GAS )
        .value( "DEVICE_PROPERTY_LIMIT_MAX_SBT_OFFSET", OPTIX_DEVICE_PROPERTY_LIMIT_MAX_SBT_OFFSET )
        .export_values();

    py::enum_<OptixDeviceContextValidationMode>(m, "DeviceContextValidationMode")
        .value( "DEVICE_CONTEXT_VALIDATION_MODE_OFF", OPTIX_DEVICE_CONTEXT_VALIDATION_MODE_OFF )
        .value( "DEVICE_CONTEXT_VALIDATION_MODE_ALL", OPTIX_DEVICE_CONTEXT_VALIDATION_MODE_ALL )
        .export_values();

    py::enum_<OptixGeometryFlags>(m, "GeometryFlags")
        .value( "GEOMETRY_FLAG_NONE", OPTIX_GEOMETRY_FLAG_NONE )
        .value( "GEOMETRY_FLAG_DISABLE_ANYHIT", OPTIX_GEOMETRY_FLAG_DISABLE_ANYHIT )
        .value( "GEOMETRY_FLAG_REQUIRE_SINGLE_ANYHIT_CALL", OPTIX_GEOMETRY_FLAG_REQUIRE_SINGLE_ANYHIT_CALL )
        .export_values();

    py::enum_<OptixHitKind>(m, "HitKind")
        .value( "HIT_KIND_TRIANGLE_FRONT_FACE", OPTIX_HIT_KIND_TRIANGLE_FRONT_FACE )
        .value( "HIT_KIND_TRIANGLE_BACK_FACE", OPTIX_HIT_KIND_TRIANGLE_BACK_FACE )
        .export_values();

    py::enum_<OptixIndicesFormat>(m, "IndicesFormat")
        .value( "INDICES_FORMAT_NONE", OPTIX_INDICES_FORMAT_NONE )
        .value( "INDICES_FORMAT_UNSIGNED_SHORT3", OPTIX_INDICES_FORMAT_UNSIGNED_SHORT3 )
        .value( "INDICES_FORMAT_UNSIGNED_INT3", OPTIX_INDICES_FORMAT_UNSIGNED_INT3 )
        .export_values();

    py::enum_<OptixVertexFormat>(m, "VertexFormat")
        .value( "VERTEX_FORMAT_NONE", OPTIX_VERTEX_FORMAT_NONE )
        .value( "VERTEX_FORMAT_FLOAT3", OPTIX_VERTEX_FORMAT_FLOAT3 )
        .value( "VERTEX_FORMAT_FLOAT2", OPTIX_VERTEX_FORMAT_FLOAT2 )
        .value( "VERTEX_FORMAT_HALF3", OPTIX_VERTEX_FORMAT_HALF3 )
        .value( "VERTEX_FORMAT_HALF2", OPTIX_VERTEX_FORMAT_HALF2 )
        .value( "VERTEX_FORMAT_SNORM16_3", OPTIX_VERTEX_FORMAT_SNORM16_3 )
        .value( "VERTEX_FORMAT_SNORM16_2", OPTIX_VERTEX_FORMAT_SNORM16_2 )
        .export_values();

    py::enum_<OptixTransformFormat>(m, "TransformFormat")
        .value( "TRANSFORM_FORMAT_NONE", OPTIX_TRANSFORM_FORMAT_NONE )
        .value( "TRANSFORM_FORMAT_MATRIX_FLOAT12", OPTIX_TRANSFORM_FORMAT_MATRIX_FLOAT12 )
        .export_values();

    py::enum_<OptixPrimitiveType>(m, "PrimitiveType")
        .value( "PRIMITIVE_TYPE_CUSTOM", OPTIX_PRIMITIVE_TYPE_CUSTOM )
        .value( "PRIMITIVE_TYPE_ROUND_QUADRATIC_BSPLINE", OPTIX_PRIMITIVE_TYPE_ROUND_QUADRATIC_BSPLINE )
        .value( "PRIMITIVE_TYPE_ROUND_CUBIC_BSPLINE", OPTIX_PRIMITIVE_TYPE_ROUND_CUBIC_BSPLINE )
        .value( "PRIMITIVE_TYPE_ROUND_LINEAR", OPTIX_PRIMITIVE_TYPE_ROUND_LINEAR )
        .value( "PRIMITIVE_TYPE_TRIANGLE", OPTIX_PRIMITIVE_TYPE_TRIANGLE )
        .export_values();

    py::enum_<OptixPrimitiveTypeFlags>(m, "PrimitiveTypeFlags")
        .value( "PRIMITIVE_TYPE_FLAGS_CUSTOM", OPTIX_PRIMITIVE_TYPE_FLAGS_CUSTOM )
        .value( "PRIMITIVE_TYPE_FLAGS_ROUND_QUADRATIC_BSPLINE", OPTIX_PRIMITIVE_TYPE_FLAGS_ROUND_QUADRATIC_BSPLINE )
        .value( "PRIMITIVE_TYPE_FLAGS_ROUND_CUBIC_BSPLINE", OPTIX_PRIMITIVE_TYPE_FLAGS_ROUND_CUBIC_BSPLINE )
        .value( "PRIMITIVE_TYPE_FLAGS_ROUND_LINEAR", OPTIX_PRIMITIVE_TYPE_FLAGS_ROUND_LINEAR )
        .value( "PRIMITIVE_TYPE_FLAGS_TRIANGLE", OPTIX_PRIMITIVE_TYPE_FLAGS_TRIANGLE )
        .export_values();

    py::enum_<OptixBuildInputType>(m, "BuildInputType")
        .value( "BUILD_INPUT_TYPE_TRIANGLES", OPTIX_BUILD_INPUT_TYPE_TRIANGLES )
        .value( "BUILD_INPUT_TYPE_CUSTOM_PRIMITIVES", OPTIX_BUILD_INPUT_TYPE_CUSTOM_PRIMITIVES )
        .value( "BUILD_INPUT_TYPE_INSTANCES", OPTIX_BUILD_INPUT_TYPE_INSTANCES )
        .value( "BUILD_INPUT_TYPE_INSTANCE_POINTERS", OPTIX_BUILD_INPUT_TYPE_INSTANCE_POINTERS )
        .value( "BUILD_INPUT_TYPE_CURVES", OPTIX_BUILD_INPUT_TYPE_CURVES )
        .export_values();

    py::enum_<OptixInstanceFlags>(m, "InstanceFlags")
        .value( "INSTANCE_FLAG_NONE", OPTIX_INSTANCE_FLAG_NONE )
        .value( "INSTANCE_FLAG_DISABLE_TRIANGLE_FACE_CULLING", OPTIX_INSTANCE_FLAG_DISABLE_TRIANGLE_FACE_CULLING )
        .value( "INSTANCE_FLAG_FLIP_TRIANGLE_FACING", OPTIX_INSTANCE_FLAG_FLIP_TRIANGLE_FACING )
        .value( "INSTANCE_FLAG_DISABLE_ANYHIT", OPTIX_INSTANCE_FLAG_DISABLE_ANYHIT )
        .value( "INSTANCE_FLAG_ENFORCE_ANYHIT", OPTIX_INSTANCE_FLAG_ENFORCE_ANYHIT )
        .value( "INSTANCE_FLAG_DISABLE_TRANSFORM", OPTIX_INSTANCE_FLAG_DISABLE_TRANSFORM )
        .export_values();

    py::enum_<OptixBuildFlags>(m, "BuildFlags")
        .value( "BUILD_FLAG_NONE", OPTIX_BUILD_FLAG_NONE )
        .value( "BUILD_FLAG_ALLOW_UPDATE", OPTIX_BUILD_FLAG_ALLOW_UPDATE )
        .value( "BUILD_FLAG_ALLOW_COMPACTION", OPTIX_BUILD_FLAG_ALLOW_COMPACTION )
        .value( "BUILD_FLAG_PREFER_FAST_TRACE", OPTIX_BUILD_FLAG_PREFER_FAST_TRACE )
        .value( "BUILD_FLAG_PREFER_FAST_BUILD", OPTIX_BUILD_FLAG_PREFER_FAST_BUILD )
        .value( "BUILD_FLAG_ALLOW_RANDOM_VERTEX_ACCESS", OPTIX_BUILD_FLAG_ALLOW_RANDOM_VERTEX_ACCESS )
        .export_values();

    py::enum_<OptixBuildOperation>(m, "BuildOperation")
        .value( "BUILD_OPERATION_BUILD", OPTIX_BUILD_OPERATION_BUILD )
        .value( "BUILD_OPERATION_UPDATE", OPTIX_BUILD_OPERATION_UPDATE )
        .export_values();

    py::enum_<OptixMotionFlags>(m, "MotionFlags")
        .value( "MOTION_FLAG_NONE", OPTIX_MOTION_FLAG_NONE )
        .value( "MOTION_FLAG_START_VANISH", OPTIX_MOTION_FLAG_START_VANISH )
        .value( "MOTION_FLAG_END_VANISH", OPTIX_MOTION_FLAG_END_VANISH )
        .export_values();

    py::enum_<OptixAccelPropertyType>(m, "AccelPropertyType")
        .value( "PROPERTY_TYPE_COMPACTED_SIZE", OPTIX_PROPERTY_TYPE_COMPACTED_SIZE )
        .value( "PROPERTY_TYPE_AABBS", OPTIX_PROPERTY_TYPE_AABBS )
        .export_values();

    py::enum_<OptixTraversableType>(m, "TraversableType")
        .value( "TRAVERSABLE_TYPE_STATIC_TRANSFORM", OPTIX_TRAVERSABLE_TYPE_STATIC_TRANSFORM )
        .value( "TRAVERSABLE_TYPE_MATRIX_MOTION_TRANSFORM", OPTIX_TRAVERSABLE_TYPE_MATRIX_MOTION_TRANSFORM )
        .value( "TRAVERSABLE_TYPE_SRT_MOTION_TRANSFORM", OPTIX_TRAVERSABLE_TYPE_SRT_MOTION_TRANSFORM )
        .export_values();

    py::enum_<OptixPixelFormat>(m, "PixelFormat")
        .value( "PIXEL_FORMAT_HALF3", OPTIX_PIXEL_FORMAT_HALF3 )
        .value( "PIXEL_FORMAT_HALF4", OPTIX_PIXEL_FORMAT_HALF4 )
        .value( "PIXEL_FORMAT_FLOAT3", OPTIX_PIXEL_FORMAT_FLOAT3 )
        .value( "PIXEL_FORMAT_FLOAT4", OPTIX_PIXEL_FORMAT_FLOAT4 )
        .value( "PIXEL_FORMAT_UCHAR3", OPTIX_PIXEL_FORMAT_UCHAR3 )
        .value( "PIXEL_FORMAT_UCHAR4", OPTIX_PIXEL_FORMAT_UCHAR4 )
        .export_values();

    py::enum_<OptixDenoiserModelKind>(m, "DenoiserModelKind")
        .value( "DENOISER_MODEL_KIND_USER", OPTIX_DENOISER_MODEL_KIND_USER )
        .value( "DENOISER_MODEL_KIND_LDR", OPTIX_DENOISER_MODEL_KIND_LDR )
        .value( "DENOISER_MODEL_KIND_HDR", OPTIX_DENOISER_MODEL_KIND_HDR )
        .value( "DENOISER_MODEL_KIND_AOV", OPTIX_DENOISER_MODEL_KIND_AOV )
        .export_values();

    py::enum_<OptixRayFlags>(m, "RayFlags")
        .value( "RAY_FLAG_NONE", OPTIX_RAY_FLAG_NONE )
        .value( "RAY_FLAG_DISABLE_ANYHIT", OPTIX_RAY_FLAG_DISABLE_ANYHIT )
        .value( "RAY_FLAG_ENFORCE_ANYHIT", OPTIX_RAY_FLAG_ENFORCE_ANYHIT )
        .value( "RAY_FLAG_TERMINATE_ON_FIRST_HIT", OPTIX_RAY_FLAG_TERMINATE_ON_FIRST_HIT )
        .value( "RAY_FLAG_DISABLE_CLOSESTHIT", OPTIX_RAY_FLAG_DISABLE_CLOSESTHIT )
        .value( "RAY_FLAG_CULL_BACK_FACING_TRIANGLES", OPTIX_RAY_FLAG_CULL_BACK_FACING_TRIANGLES )
        .value( "RAY_FLAG_CULL_FRONT_FACING_TRIANGLES", OPTIX_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES )
        .value( "RAY_FLAG_CULL_DISABLED_ANYHIT", OPTIX_RAY_FLAG_CULL_DISABLED_ANYHIT )
        .value( "RAY_FLAG_CULL_ENFORCED_ANYHIT", OPTIX_RAY_FLAG_CULL_ENFORCED_ANYHIT )
        .export_values();

    py::enum_<OptixTransformType>(m, "TransformType")
        .value( "TRANSFORM_TYPE_NONE", OPTIX_TRANSFORM_TYPE_NONE )
        .value( "TRANSFORM_TYPE_STATIC_TRANSFORM", OPTIX_TRANSFORM_TYPE_STATIC_TRANSFORM )
        .value( "TRANSFORM_TYPE_MATRIX_MOTION_TRANSFORM", OPTIX_TRANSFORM_TYPE_MATRIX_MOTION_TRANSFORM )
        .value( "TRANSFORM_TYPE_SRT_MOTION_TRANSFORM", OPTIX_TRANSFORM_TYPE_SRT_MOTION_TRANSFORM )
        .value( "TRANSFORM_TYPE_INSTANCE", OPTIX_TRANSFORM_TYPE_INSTANCE )
        .export_values();

    py::enum_<OptixTraversableGraphFlags>(m, "TraversableGraphFlags")
        .value( "TRAVERSABLE_GRAPH_FLAG_ALLOW_ANY", OPTIX_TRAVERSABLE_GRAPH_FLAG_ALLOW_ANY )
        .value( "TRAVERSABLE_GRAPH_FLAG_ALLOW_SINGLE_GAS", OPTIX_TRAVERSABLE_GRAPH_FLAG_ALLOW_SINGLE_GAS )
        .value( "TRAVERSABLE_GRAPH_FLAG_ALLOW_SINGLE_LEVEL_INSTANCING", OPTIX_TRAVERSABLE_GRAPH_FLAG_ALLOW_SINGLE_LEVEL_INSTANCING )
        .export_values();

    py::enum_<OptixCompileOptimizationLevel>(m, "CompileOptimizationLevel")
        .value( "COMPILE_OPTIMIZATION_DEFAULT", OPTIX_COMPILE_OPTIMIZATION_DEFAULT )
        .value( "COMPILE_OPTIMIZATION_LEVEL_0", OPTIX_COMPILE_OPTIMIZATION_LEVEL_0 )
        .value( "COMPILE_OPTIMIZATION_LEVEL_1", OPTIX_COMPILE_OPTIMIZATION_LEVEL_1 )
        .value( "COMPILE_OPTIMIZATION_LEVEL_2", OPTIX_COMPILE_OPTIMIZATION_LEVEL_2 )
        .value( "COMPILE_OPTIMIZATION_LEVEL_3", OPTIX_COMPILE_OPTIMIZATION_LEVEL_3 )
        .export_values();

    py::enum_<OptixCompileDebugLevel>(m, "CompileDebugLevel")
        .value( "COMPILE_DEBUG_LEVEL_DEFAULT", OPTIX_COMPILE_DEBUG_LEVEL_DEFAULT )
        .value( "COMPILE_DEBUG_LEVEL_NONE", OPTIX_COMPILE_DEBUG_LEVEL_NONE )
        .value( "COMPILE_DEBUG_LEVEL_LINEINFO", OPTIX_COMPILE_DEBUG_LEVEL_LINEINFO )
        .value( "COMPILE_DEBUG_LEVEL_FULL", OPTIX_COMPILE_DEBUG_LEVEL_FULL )
        .export_values();

    py::enum_<OptixProgramGroupKind>(m, "ProgramGroupKind")
        .value( "PROGRAM_GROUP_KIND_RAYGEN", OPTIX_PROGRAM_GROUP_KIND_RAYGEN )
        .value( "PROGRAM_GROUP_KIND_MISS", OPTIX_PROGRAM_GROUP_KIND_MISS )
        .value( "PROGRAM_GROUP_KIND_EXCEPTION", OPTIX_PROGRAM_GROUP_KIND_EXCEPTION )
        .value( "PROGRAM_GROUP_KIND_HITGROUP", OPTIX_PROGRAM_GROUP_KIND_HITGROUP )
        .value( "PROGRAM_GROUP_KIND_CALLABLES", OPTIX_PROGRAM_GROUP_KIND_CALLABLES )
        .export_values();

    py::enum_<OptixProgramGroupFlags>(m, "ProgramGroupFlags")
        .value( "PROGRAM_GROUP_FLAGS_NONE", OPTIX_PROGRAM_GROUP_FLAGS_NONE )
        .export_values();

    py::enum_<OptixExceptionCodes>(m, "ExceptionCodes")
        .value( "EXCEPTION_CODE_STACK_OVERFLOW", OPTIX_EXCEPTION_CODE_STACK_OVERFLOW )
        .value( "EXCEPTION_CODE_TRACE_DEPTH_EXCEEDED", OPTIX_EXCEPTION_CODE_TRACE_DEPTH_EXCEEDED )
        .value( "EXCEPTION_CODE_TRAVERSAL_DEPTH_EXCEEDED", OPTIX_EXCEPTION_CODE_TRAVERSAL_DEPTH_EXCEEDED )
        .value( "EXCEPTION_CODE_TRAVERSAL_INVALID_TRAVERSABLE", OPTIX_EXCEPTION_CODE_TRAVERSAL_INVALID_TRAVERSABLE )
        .value( "EXCEPTION_CODE_TRAVERSAL_INVALID_MISS_SBT", OPTIX_EXCEPTION_CODE_TRAVERSAL_INVALID_MISS_SBT )
        .value( "EXCEPTION_CODE_TRAVERSAL_INVALID_HIT_SBT", OPTIX_EXCEPTION_CODE_TRAVERSAL_INVALID_HIT_SBT )
        .value( "EXCEPTION_CODE_UNSUPPORTED_PRIMITIVE_TYPE", OPTIX_EXCEPTION_CODE_UNSUPPORTED_PRIMITIVE_TYPE )
        .value( "EXCEPTION_CODE_INVALID_RAY", OPTIX_EXCEPTION_CODE_INVALID_RAY )
        .value( "EXCEPTION_CODE_CALLABLE_PARAMETER_MISMATCH", OPTIX_EXCEPTION_CODE_CALLABLE_PARAMETER_MISMATCH )
        .value( "EXCEPTION_CODE_BUILTIN_IS_MISMATCH", OPTIX_EXCEPTION_CODE_BUILTIN_IS_MISMATCH )
        .value( "EXCEPTION_CODE_CALLABLE_INVALID_SBT", OPTIX_EXCEPTION_CODE_CALLABLE_INVALID_SBT )
        .value( "EXCEPTION_CODE_CALLABLE_NO_DC_SBT_RECORD", OPTIX_EXCEPTION_CODE_CALLABLE_NO_DC_SBT_RECORD )
        .value( "EXCEPTION_CODE_CALLABLE_NO_CC_SBT_RECORD", OPTIX_EXCEPTION_CODE_CALLABLE_NO_CC_SBT_RECORD )
        .value( "EXCEPTION_CODE_UNSUPPORTED_SINGLE_LEVEL_GAS", OPTIX_EXCEPTION_CODE_UNSUPPORTED_SINGLE_LEVEL_GAS )
        .export_values();

    py::enum_<OptixExceptionFlags>(m, "ExceptionFlags")
        .value( "EXCEPTION_FLAG_NONE", OPTIX_EXCEPTION_FLAG_NONE )
        .value( "EXCEPTION_FLAG_STACK_OVERFLOW", OPTIX_EXCEPTION_FLAG_STACK_OVERFLOW )
        .value( "EXCEPTION_FLAG_TRACE_DEPTH", OPTIX_EXCEPTION_FLAG_TRACE_DEPTH )
        .value( "EXCEPTION_FLAG_USER", OPTIX_EXCEPTION_FLAG_USER )
        .value( "EXCEPTION_FLAG_DEBUG", OPTIX_EXCEPTION_FLAG_DEBUG )
        .export_values();

    py::enum_<OptixQueryFunctionTableOptions>(m, "QueryFunctionTableOptions")
        .value( "QUERY_FUNCTION_TABLE_OPTION_DUMMY", OPTIX_QUERY_FUNCTION_TABLE_OPTION_DUMMY )
        .export_values();

    
    //---------------------------------------------------------------------------
    //
    // Param types
    //
    //---------------------------------------------------------------------------

    py::class_<OptixDeviceContextOptions>(m, "DeviceContextOptions")
        .def( py::init([]() { return std::unique_ptr<OptixDeviceContextOptions>(new OptixDeviceContextOptions{} ); } ) )
        .def_readwrite( "logCallbackFunction", &OptixDeviceContextOptions::logCallbackFunction )
        .def_readwrite( "logCallbackData", &OptixDeviceContextOptions::logCallbackData )
        .def_readwrite( "logCallbackLevel", &OptixDeviceContextOptions::logCallbackLevel )
        .def_readwrite( "validationMode", &OptixDeviceContextOptions::validationMode )
        ;

    py::class_<OptixBuildInputTriangleArray>(m, "BuildInputTriangleArray")
        .def( py::init([]() { return std::unique_ptr<OptixBuildInputTriangleArray>(new OptixBuildInputTriangleArray{} ); } ) )
        .def_readwrite( "vertexBuffers", &OptixBuildInputTriangleArray::vertexBuffers )
        .def_readwrite( "numVertices", &OptixBuildInputTriangleArray::numVertices )
        .def_readwrite( "vertexFormat", &OptixBuildInputTriangleArray::vertexFormat )
        .def_readwrite( "vertexStrideInBytes", &OptixBuildInputTriangleArray::vertexStrideInBytes )
        .def_readwrite( "indexBuffer", &OptixBuildInputTriangleArray::indexBuffer )
        .def_readwrite( "numIndexTriplets", &OptixBuildInputTriangleArray::numIndexTriplets )
        .def_readwrite( "indexFormat", &OptixBuildInputTriangleArray::indexFormat )
        .def_readwrite( "indexStrideInBytes", &OptixBuildInputTriangleArray::indexStrideInBytes )
        .def_readwrite( "preTransform", &OptixBuildInputTriangleArray::preTransform )
        .def_readwrite( "flags", &OptixBuildInputTriangleArray::flags )
        .def_readwrite( "numSbtRecords", &OptixBuildInputTriangleArray::numSbtRecords )
        .def_readwrite( "sbtIndexOffsetBuffer", &OptixBuildInputTriangleArray::sbtIndexOffsetBuffer )
        .def_readwrite( "sbtIndexOffsetSizeInBytes", &OptixBuildInputTriangleArray::sbtIndexOffsetSizeInBytes )
        .def_readwrite( "sbtIndexOffsetStrideInBytes", &OptixBuildInputTriangleArray::sbtIndexOffsetStrideInBytes )
        .def_readwrite( "primitiveIndexOffset", &OptixBuildInputTriangleArray::primitiveIndexOffset )
        .def_readwrite( "transformFormat", &OptixBuildInputTriangleArray::transformFormat )
        ;

    py::class_<OptixBuildInputCurveArray>(m, "BuildInputCurveArray")
        .def( py::init([]() { return std::unique_ptr<OptixBuildInputCurveArray>(new OptixBuildInputCurveArray{} ); } ) )
        .def_readwrite( "curveType", &OptixBuildInputCurveArray::curveType )
        .def_readwrite( "numPrimitives", &OptixBuildInputCurveArray::numPrimitives )
        .def_readwrite( "vertexBuffers", &OptixBuildInputCurveArray::vertexBuffers )
        .def_readwrite( "numVertices", &OptixBuildInputCurveArray::numVertices )
        .def_readwrite( "vertexStrideInBytes", &OptixBuildInputCurveArray::vertexStrideInBytes )
        .def_readwrite( "widthBuffers", &OptixBuildInputCurveArray::widthBuffers )
        .def_readwrite( "widthStrideInBytes", &OptixBuildInputCurveArray::widthStrideInBytes )
        .def_readwrite( "normalBuffers", &OptixBuildInputCurveArray::normalBuffers )
        .def_readwrite( "normalStrideInBytes", &OptixBuildInputCurveArray::normalStrideInBytes )
        .def_readwrite( "indexBuffer", &OptixBuildInputCurveArray::indexBuffer )
        .def_readwrite( "indexStrideInBytes", &OptixBuildInputCurveArray::indexStrideInBytes )
        .def_readwrite( "flag", &OptixBuildInputCurveArray::flag )
        .def_readwrite( "primitiveIndexOffset", &OptixBuildInputCurveArray::primitiveIndexOffset )
        ;

    py::class_<OptixAabb>(m, "Aabb")
        .def( py::init([]() { return std::unique_ptr<OptixAabb>(new OptixAabb{} ); } ) )
        .def_readwrite( "minX", &OptixAabb::minX )
        .def_readwrite( "minY", &OptixAabb::minY )
        .def_readwrite( "minZ", &OptixAabb::minZ )
        .def_readwrite( "maxX", &OptixAabb::maxX )
        .def_readwrite( "maxY", &OptixAabb::maxY )
        .def_readwrite( "maxZ", &OptixAabb::maxZ )
        ;

    py::class_<OptixBuildInputCustomPrimitiveArray>(m, "BuildInputCustomPrimitiveArray")
        .def( py::init([]() { return std::unique_ptr<OptixBuildInputCustomPrimitiveArray>(new OptixBuildInputCustomPrimitiveArray{} ); } ) )
        .def_readwrite( "aabbBuffers", &OptixBuildInputCustomPrimitiveArray::aabbBuffers )
        .def_readwrite( "numPrimitives", &OptixBuildInputCustomPrimitiveArray::numPrimitives )
        .def_readwrite( "strideInBytes", &OptixBuildInputCustomPrimitiveArray::strideInBytes )
        .def_readwrite( "flags", &OptixBuildInputCustomPrimitiveArray::flags )
        .def_readwrite( "numSbtRecords", &OptixBuildInputCustomPrimitiveArray::numSbtRecords )
        .def_readwrite( "sbtIndexOffsetBuffer", &OptixBuildInputCustomPrimitiveArray::sbtIndexOffsetBuffer )
        .def_readwrite( "sbtIndexOffsetSizeInBytes", &OptixBuildInputCustomPrimitiveArray::sbtIndexOffsetSizeInBytes )
        .def_readwrite( "sbtIndexOffsetStrideInBytes", &OptixBuildInputCustomPrimitiveArray::sbtIndexOffsetStrideInBytes )
        .def_readwrite( "primitiveIndexOffset", &OptixBuildInputCustomPrimitiveArray::primitiveIndexOffset )
        ;

    py::class_<OptixBuildInputInstanceArray>(m, "BuildInputInstanceArray")
        .def( py::init([]() { return std::unique_ptr<OptixBuildInputInstanceArray>(new OptixBuildInputInstanceArray{} ); } ) )
        .def_readwrite( "instances", &OptixBuildInputInstanceArray::instances )
        .def_readwrite( "numInstances", &OptixBuildInputInstanceArray::numInstances )
        ;

    py::class_<OptixBuildInput>(m, "BuildInput")
        .def( py::init([]() { return std::unique_ptr<OptixBuildInput>(new OptixBuildInput{} ); } ) )
        .def_readwrite( "type", &OptixBuildInput::type )
        .def_readwrite( "triangleArray", &OptixBuildInput::triangleArray )
        .def_readwrite( "curveArray", &OptixBuildInput::curveArray )
        .def_readwrite( "customPrimitiveArray", &OptixBuildInput::customPrimitiveArray )
        .def_readwrite( "instanceArray", &OptixBuildInput::instanceArray )
        ;

    py::class_<OptixInstance>(m, "Instance")
        .def( py::init([]() { return std::unique_ptr<OptixInstance>(new OptixInstance{} ); } ) )
        .def_readwrite( "instanceId", &OptixInstance::instanceId )
        .def_readwrite( "sbtOffset", &OptixInstance::sbtOffset )
        .def_readwrite( "visibilityMask", &OptixInstance::visibilityMask )
        .def_readwrite( "flags", &OptixInstance::flags )
        .def_readwrite( "traversableHandle", &OptixInstance::traversableHandle )
        ;

    py::class_<OptixMotionOptions>(m, "MotionOptions")
        .def( py::init([]() { return std::unique_ptr<OptixMotionOptions>(new OptixMotionOptions{} ); } ) )
        .def_readwrite( "numKeys", &OptixMotionOptions::numKeys )
        .def_readwrite( "flags", &OptixMotionOptions::flags )
        .def_readwrite( "timeBegin", &OptixMotionOptions::timeBegin )
        .def_readwrite( "timeEnd", &OptixMotionOptions::timeEnd )
        ;

    py::class_<OptixAccelBuildOptions>(m, "AccelBuildOptions")
        .def( py::init([]() { return std::unique_ptr<OptixAccelBuildOptions>(new OptixAccelBuildOptions{} ); } ) )
        .def_readwrite( "buildFlags", &OptixAccelBuildOptions::buildFlags )
        .def_readwrite( "operation", &OptixAccelBuildOptions::operation )
        .def_readwrite( "motionOptions", &OptixAccelBuildOptions::motionOptions )
        ;

    py::class_<OptixAccelBufferSizes>(m, "AccelBufferSizes")
        .def( py::init([]() { return std::unique_ptr<OptixAccelBufferSizes>(new OptixAccelBufferSizes{} ); } ) )
        .def_readwrite( "outputSizeInBytes", &OptixAccelBufferSizes::outputSizeInBytes )
        .def_readwrite( "tempSizeInBytes", &OptixAccelBufferSizes::tempSizeInBytes )
        .def_readwrite( "tempUpdateSizeInBytes", &OptixAccelBufferSizes::tempUpdateSizeInBytes )
        ;

    py::class_<OptixAccelEmitDesc>(m, "AccelEmitDesc")
        .def( py::init([]() { return std::unique_ptr<OptixAccelEmitDesc>(new OptixAccelEmitDesc{} ); } ) )
        .def_readwrite( "result", &OptixAccelEmitDesc::result )
        .def_readwrite( "type", &OptixAccelEmitDesc::type )
        ;

    py::class_<OptixAccelRelocationInfo>(m, "AccelRelocationInfo")
        .def( py::init([]() { return std::unique_ptr<OptixAccelRelocationInfo>(new OptixAccelRelocationInfo{} ); } ) )
        ;

    py::class_<OptixStaticTransform>(m, "StaticTransform")
        .def( py::init([]() { return std::unique_ptr<OptixStaticTransform>(new OptixStaticTransform{} ); } ) )
        .def_readwrite( "child", &OptixStaticTransform::child )
        ;

    py::class_<OptixMatrixMotionTransform>(m, "MatrixMotionTransform")
        .def( py::init([]() { return std::unique_ptr<OptixMatrixMotionTransform>(new OptixMatrixMotionTransform{} ); } ) )
        .def_readwrite( "child", &OptixMatrixMotionTransform::child )
        .def_readwrite( "motionOptions", &OptixMatrixMotionTransform::motionOptions )
        ;

    py::class_<OptixSRTData>(m, "SRTData")
        .def( py::init([]() { return std::unique_ptr<OptixSRTData>(new OptixSRTData{} ); } ) )
        .def_readwrite( "tz", &OptixSRTData::tz )
        ;

    py::class_<OptixSRTMotionTransform>(m, "SRTMotionTransform")
        .def( py::init([]() { return std::unique_ptr<OptixSRTMotionTransform>(new OptixSRTMotionTransform{} ); } ) )
        .def_readwrite( "child", &OptixSRTMotionTransform::child )
        .def_readwrite( "motionOptions", &OptixSRTMotionTransform::motionOptions )
        ;

    py::class_<OptixImage2D>(m, "Image2D")
        .def( py::init([]() { return std::unique_ptr<OptixImage2D>(new OptixImage2D{} ); } ) )
        .def_readwrite( "data", &OptixImage2D::data )
        .def_readwrite( "width", &OptixImage2D::width )
        .def_readwrite( "height", &OptixImage2D::height )
        .def_readwrite( "rowStrideInBytes", &OptixImage2D::rowStrideInBytes )
        .def_readwrite( "pixelStrideInBytes", &OptixImage2D::pixelStrideInBytes )
        .def_readwrite( "format", &OptixImage2D::format )
        ;

    py::class_<OptixDenoiserOptions>(m, "DenoiserOptions")
        .def( py::init([]() { return std::unique_ptr<OptixDenoiserOptions>(new OptixDenoiserOptions{} ); } ) )
        .def_readwrite( "inputKind", &OptixDenoiserOptions::inputKind )
        ;

    py::class_<OptixDenoiserParams>(m, "DenoiserParams")
        .def( py::init([]() { return std::unique_ptr<OptixDenoiserParams>(new OptixDenoiserParams{} ); } ) )
        .def_readwrite( "denoiseAlpha", &OptixDenoiserParams::denoiseAlpha )
        .def_readwrite( "hdrIntensity", &OptixDenoiserParams::hdrIntensity )
        .def_readwrite( "blendFactor", &OptixDenoiserParams::blendFactor )
        .def_readwrite( "hdrAverageColor", &OptixDenoiserParams::hdrAverageColor )
        ;

    py::class_<OptixDenoiserSizes>(m, "DenoiserSizes")
        .def( py::init([]() { return std::unique_ptr<OptixDenoiserSizes>(new OptixDenoiserSizes{} ); } ) )
        .def_readwrite( "stateSizeInBytes", &OptixDenoiserSizes::stateSizeInBytes )
        .def_readwrite( "withOverlapScratchSizeInBytes", &OptixDenoiserSizes::withOverlapScratchSizeInBytes )
        .def_readwrite( "withoutOverlapScratchSizeInBytes", &OptixDenoiserSizes::withoutOverlapScratchSizeInBytes )
        .def_readwrite( "overlapWindowSizeInPixels", &OptixDenoiserSizes::overlapWindowSizeInPixels )
        ;

    py::class_<OptixModuleCompileBoundValueEntry>(m, "ModuleCompileBoundValueEntry")
        .def( py::init([]() { return std::unique_ptr<OptixModuleCompileBoundValueEntry>(new OptixModuleCompileBoundValueEntry{} ); } ) )
        .def_readwrite( "pipelineParamOffsetInBytes", &OptixModuleCompileBoundValueEntry::pipelineParamOffsetInBytes )
        .def_readwrite( "sizeInBytes", &OptixModuleCompileBoundValueEntry::sizeInBytes )
        .def_readwrite( "boundValuePtr", &OptixModuleCompileBoundValueEntry::boundValuePtr )
        .def_readwrite( "annotation", &OptixModuleCompileBoundValueEntry::annotation )
        ;

    py::class_<OptixModuleCompileOptions>(m, "ModuleCompileOptions")
        .def( py::init([]() { return std::unique_ptr<OptixModuleCompileOptions>(new OptixModuleCompileOptions{} ); } ) )
        .def_readwrite( "maxRegisterCount", &OptixModuleCompileOptions::maxRegisterCount )
        .def_readwrite( "optLevel", &OptixModuleCompileOptions::optLevel )
        .def_readwrite( "debugLevel", &OptixModuleCompileOptions::debugLevel )
        .def_readwrite( "boundValues", &OptixModuleCompileOptions::boundValues )
        .def_readwrite( "numBoundValues", &OptixModuleCompileOptions::numBoundValues )
        ;

    py::class_<OptixProgramGroupSingleModule>(m, "ProgramGroupSingleModule")
        .def( py::init([]() { return std::unique_ptr<OptixProgramGroupSingleModule>(new OptixProgramGroupSingleModule{} ); } ) )
        //.def_readwrite( "module", &OptixProgramGroupSingleModule::module, py::return_value_policy::reference)
        //.def_readwrite( "entryFunctionName", &OptixProgramGroupSingleModule::entryFunctionName )
        ;

    py::class_<OptixProgramGroupHitgroup>(m, "ProgramGroupHitgroup")
        .def( py::init([]() { return std::unique_ptr<OptixProgramGroupHitgroup>(new OptixProgramGroupHitgroup{} ); } ) )
        /*
        .def_readwrite( "moduleCH", &OptixProgramGroupHitgroup::moduleCH )
        .def_readwrite( "entryFunctionNameCH", &OptixProgramGroupHitgroup::entryFunctionNameCH )
        .def_readwrite( "moduleAH", &OptixProgramGroupHitgroup::moduleAH )
        .def_readwrite( "entryFunctionNameAH", &OptixProgramGroupHitgroup::entryFunctionNameAH )
        .def_readwrite( "moduleIS", &OptixProgramGroupHitgroup::moduleIS )
        .def_readwrite( "entryFunctionNameIS", &OptixProgramGroupHitgroup::entryFunctionNameIS )
        */
        ;

    py::class_<OptixProgramGroupCallables>(m, "ProgramGroupCallables")
        .def( py::init([]() { return std::unique_ptr<OptixProgramGroupCallables>(new OptixProgramGroupCallables{} ); } ) )
        /*
        .def_readwrite( "moduleDC", &OptixProgramGroupCallables::moduleDC )
        .def_readwrite( "entryFunctionNameDC", &OptixProgramGroupCallables::entryFunctionNameDC )
        .def_readwrite( "moduleCC", &OptixProgramGroupCallables::moduleCC )
        .def_readwrite( "entryFunctionNameCC", &OptixProgramGroupCallables::entryFunctionNameCC )
        */
        ;

    py::class_<OptixProgramGroupDesc>(m, "ProgramGroupDesc")
        .def( py::init([]() { return std::unique_ptr<OptixProgramGroupDesc>(new OptixProgramGroupDesc{} ); } ) )
        .def_readwrite( "kind", &OptixProgramGroupDesc::kind )
        .def_readwrite( "flags", &OptixProgramGroupDesc::flags )
        .def_readwrite( "raygen", &OptixProgramGroupDesc::raygen )
        .def_readwrite( "miss", &OptixProgramGroupDesc::miss )
        .def_readwrite( "exception", &OptixProgramGroupDesc::exception )
        .def_readwrite( "callables", &OptixProgramGroupDesc::callables )
        .def_readwrite( "hitgroup", &OptixProgramGroupDesc::hitgroup )
        ;

    py::class_<OptixProgramGroupOptions>(m, "ProgramGroupOptions")
        .def( py::init([]() { return std::unique_ptr<OptixProgramGroupOptions>(new OptixProgramGroupOptions{} ); } ) )
        .def_readwrite( "placeholder", &OptixProgramGroupOptions::placeholder )
        ;

    py::class_<OptixPipelineCompileOptions>(m, "PipelineCompileOptions")
        .def( py::init([]() { return std::unique_ptr<OptixPipelineCompileOptions>(new OptixPipelineCompileOptions{} ); } ) )
        .def_readwrite( "usesMotionBlur", &OptixPipelineCompileOptions::usesMotionBlur )
        .def_readwrite( "traversableGraphFlags", &OptixPipelineCompileOptions::traversableGraphFlags )
        .def_readwrite( "numPayloadValues", &OptixPipelineCompileOptions::numPayloadValues )
        .def_readwrite( "numAttributeValues", &OptixPipelineCompileOptions::numAttributeValues )
        .def_readwrite( "exceptionFlags", &OptixPipelineCompileOptions::exceptionFlags )
        .def_readwrite( "pipelineLaunchParamsVariableName", &OptixPipelineCompileOptions::pipelineLaunchParamsVariableName )
        .def_readwrite( "usesPrimitiveTypeFlags", &OptixPipelineCompileOptions::usesPrimitiveTypeFlags )
        ;

    py::class_<OptixPipelineLinkOptions>(m, "PipelineLinkOptions")
        .def( py::init([]() { return std::unique_ptr<OptixPipelineLinkOptions>(new OptixPipelineLinkOptions{} ); } ) )
        .def_readwrite( "maxTraceDepth", &OptixPipelineLinkOptions::maxTraceDepth )
        .def_readwrite( "debugLevel", &OptixPipelineLinkOptions::debugLevel )
        ;

    py::class_<OptixShaderBindingTable>(m, "ShaderBindingTable")
        .def( py::init([]() { return std::unique_ptr<OptixShaderBindingTable>(new OptixShaderBindingTable{} ); } ) )
        .def_readwrite( "raygenRecord", &OptixShaderBindingTable::raygenRecord )
        .def_readwrite( "exceptionRecord", &OptixShaderBindingTable::exceptionRecord )
        .def_readwrite( "missRecordBase", &OptixShaderBindingTable::missRecordBase )
        .def_readwrite( "missRecordStrideInBytes", &OptixShaderBindingTable::missRecordStrideInBytes )
        .def_readwrite( "missRecordCount", &OptixShaderBindingTable::missRecordCount )
        .def_readwrite( "hitgroupRecordBase", &OptixShaderBindingTable::hitgroupRecordBase )
        .def_readwrite( "hitgroupRecordStrideInBytes", &OptixShaderBindingTable::hitgroupRecordStrideInBytes )
        .def_readwrite( "hitgroupRecordCount", &OptixShaderBindingTable::hitgroupRecordCount )
        .def_readwrite( "callablesRecordBase", &OptixShaderBindingTable::callablesRecordBase )
        .def_readwrite( "callablesRecordStrideInBytes", &OptixShaderBindingTable::callablesRecordStrideInBytes )
        .def_readwrite( "callablesRecordCount", &OptixShaderBindingTable::callablesRecordCount )
        ;

    py::class_<OptixStackSizes>(m, "StackSizes")
        .def( py::init([]() { return std::unique_ptr<OptixStackSizes>(new OptixStackSizes{} ); } ) )
        .def_readwrite( "cssRG", &OptixStackSizes::cssRG )
        .def_readwrite( "cssMS", &OptixStackSizes::cssMS )
        .def_readwrite( "cssCH", &OptixStackSizes::cssCH )
        .def_readwrite( "cssAH", &OptixStackSizes::cssAH )
        .def_readwrite( "cssIS", &OptixStackSizes::cssIS )
        .def_readwrite( "cssCC", &OptixStackSizes::cssCC )
        .def_readwrite( "dssDC", &OptixStackSizes::dssDC )
        ;

    py::class_<OptixBuiltinISOptions>(m, "BuiltinISOptions")
        .def( py::init([]() { return std::unique_ptr<OptixBuiltinISOptions>(new OptixBuiltinISOptions{} ); } ) )
        .def_readwrite( "builtinISModuleType", &OptixBuiltinISOptions::builtinISModuleType )
        .def_readwrite( "usesMotionBlur", &OptixBuiltinISOptions::usesMotionBlur )
        ;


    //---------------------------------------------------------------------------
    //
    // Opaque types
    //
    //---------------------------------------------------------------------------
    
    /*
    py::class_<OptixDeviceContext>( m, "DeviceContext" )
        .def( "destroy", &pyoptix::deviceContextDestroy )
        .def( "getProperty", &pyoptix::deviceContextGetProperty )
        .def( "setLogCallback", &pyoptix::deviceContextSetLogCallback )
        .def( "setCacheEnabled", &pyoptix::deviceContextSetCacheEnabled )
        .def( "setCacheLocation", &pyoptix::deviceContextSetCacheLocation )
        .def( "setCacheDatabaseSizes", &pyoptix::deviceContextSetCacheDatabaseSizes )
        .def( "getCacheEnabled", &pyoptix::deviceContextGetCacheEnabled )
        .def( "getCacheLocation", &pyoptix::deviceContextGetCacheLocation )
        .def( "getCacheDatabaseSizes", &pyoptix::deviceContextGetCacheDatabaseSizes )
        .def( "pipelineCreate", &pyoptix::pipelineCreate )
        .def( "moduleCreateFromPTX", &pyoptix::moduleCreateFromPTX )
        .def( "moduleBuiltinISGet", &pyoptix::deviceContextModuleBuiltinISGet )
        .def( "programGroupCreate", &pyoptix::programGroupCreate )
        .def( "accelComputeMemoryUsage", &pyoptix::deviceContextAccelComputeMemoryUsage )
        .def( "accelBuild", &pyoptix::deviceContextAccelBuild )
        .def( "accelGetRelocationInfo", &pyoptix::deviceContextAccelGetRelocationInfo )
        .def( "accelCheckRelocationCompatibility", &pyoptix::deviceContextAccelCheckRelocationCompatibility )
        .def( "accelRelocate", &pyoptix::deviceContextAccelRelocate )
        .def( "accelCompact", &pyoptix::deviceContextAccelCompact )
        .def( "denoiserCreate", &pyoptix::denoiserCreate )
        ;

    py::class_<OptixModule>( m, "Module" )
        .def( "destroy", &pyoptix::moduleDestroy )
        ;

    py::class_<OptixProgramGroup>( m, "ProgramGroup" )
        .def( "getStackSize", &pyoptix::programGroupGetStackSize )
        .def( "destroy", &pyoptix::programGroupDestroy )
        ;

    py::class_<OptixPipeline>( m, "Pipeline" )
        .def( "destroy", &pyoptix::pipelineDestroy )
        .def( "setStackSize", &pyoptix::pipelineSetStackSize )
        ;

    py::class_<OptixDenoiser>( m, "Denoiser" )
        .def( "setModel", &pyoptix::denoiserSetModel )
        .def( "destroy", &pyoptix::denoiserDestroy )
        .def( "computeMemoryResources", &pyoptix::denoiserComputeMemoryResources )
        .def( "setup", &pyoptix::denoiserSetup )
        .def( "invoke", &pyoptix::denoiserInvoke )
        .def( "computeIntensity", &pyoptix::denoiserComputeIntensity )
        .def( "computeAverageColor", &pyoptix::denoiserComputeAverageColor )
        ;

    */
}

