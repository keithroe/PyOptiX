
draw_color_ptx = '''
//
// Generated by NVIDIA NVVM Compiler
//
// Compiler Build ID: CL-28358933
// Cuda compilation tools, release 11.0, V11.0.167
// Based on LLVM 3.4svn
//

.version 7.0
.target sm_60
.address_size 64

	// .globl	__raygen__draw_solid_color
.visible .const .align 8 .b8 params[16];

.visible .entry __raygen__draw_solid_color(

)
{
	.reg .pred 	%p<4>;
	.reg .b16 	%rs<5>;
	.reg .f32 	%f<39>;
	.reg .b32 	%r<13>;
	.reg .b64 	%rd<6>;


	.loc 2 1603 5
	// inline asm
	call (%r1), _optix_get_launch_index_x, ();
	// inline asm
	.loc 2 1604 5
	// inline asm
	call (%r2), _optix_get_launch_index_y, ();
	// inline asm
	.loc 2 1631 5
	// inline asm
	call (%rd1), _optix_get_sbt_data_ptr_64, ();
	// inline asm
	.loc 1 43 5
	ld.const.u64 	%rd2, [params];
	cvta.to.global.u64 	%rd3, %rd2;
	ld.const.u32 	%r4, [params+8];
	mad.lo.s32 	%r5, %r4, %r2, %r1;
	ld.f32 	%f1, [%rd1];
	ld.f32 	%f2, [%rd1+4];
	ld.f32 	%f3, [%rd1+8];
	mov.f32 	%f4, 0f3F800000;
	.loc 4 121 22
	min.ftz.f32 	%f5, %f1, %f4;
	mov.f32 	%f6, 0f00000000;
	.loc 4 121 12
	max.ftz.f32 	%f7, %f6, %f5;
	.loc 4 121 22
	min.ftz.f32 	%f8, %f2, %f4;
	.loc 4 121 12
	max.ftz.f32 	%f9, %f6, %f8;
	.loc 4 121 22
	min.ftz.f32 	%f10, %f3, %f4;
	.loc 4 121 12
	max.ftz.f32 	%f11, %f6, %f10;
	.loc 3 38 36
	lg2.approx.ftz.f32 	%f12, %f7;
	mul.ftz.f32 	%f13, %f12, 0f3ED55555;
	ex2.approx.ftz.f32 	%f14, %f13;
	.loc 3 38 59
	lg2.approx.ftz.f32 	%f15, %f9;
	mul.ftz.f32 	%f16, %f15, 0f3ED55555;
	ex2.approx.ftz.f32 	%f17, %f16;
	.loc 3 38 82
	lg2.approx.ftz.f32 	%f18, %f11;
	mul.ftz.f32 	%f19, %f18, 0f3ED55555;
	ex2.approx.ftz.f32 	%f20, %f19;
	setp.lt.ftz.f32	%p1, %f7, 0f3B4D2E1C;
	mul.ftz.f32 	%f21, %f7, 0f414EB852;
	fma.rn.ftz.f32 	%f22, %f14, 0f3F870A3D, 0fBD6147AE;
	selp.f32	%f23, %f21, %f22, %p1;
	setp.lt.ftz.f32	%p2, %f9, 0f3B4D2E1C;
	mul.ftz.f32 	%f24, %f9, 0f414EB852;
	fma.rn.ftz.f32 	%f25, %f17, 0f3F870A3D, 0fBD6147AE;
	selp.f32	%f26, %f24, %f25, %p2;
	setp.lt.ftz.f32	%p3, %f11, 0f3B4D2E1C;
	mul.ftz.f32 	%f27, %f11, 0f414EB852;
	fma.rn.ftz.f32 	%f28, %f20, 0f3F870A3D, 0fBD6147AE;
	selp.f32	%f29, %f27, %f28, %p3;
	.loc 4 121 22
	min.ftz.f32 	%f30, %f23, %f4;
	.loc 4 121 12
	max.ftz.f32 	%f31, %f6, %f30;
	.loc 3 54 5
	mul.ftz.f32 	%f32, %f31, 0f43800000;
	cvt.rzi.ftz.u32.f32	%r6, %f32;
	.loc 5 868 10
	mov.u32 	%r7, 255;
	min.u32 	%r8, %r6, %r7;
	.loc 4 121 22
	min.ftz.f32 	%f33, %f26, %f4;
	.loc 4 121 12
	max.ftz.f32 	%f34, %f6, %f33;
	.loc 3 54 5
	mul.ftz.f32 	%f35, %f34, 0f43800000;
	cvt.rzi.ftz.u32.f32	%r9, %f35;
	.loc 5 868 10
	min.u32 	%r10, %r9, %r7;
	.loc 4 121 22
	min.ftz.f32 	%f36, %f29, %f4;
	.loc 4 121 12
	max.ftz.f32 	%f37, %f6, %f36;
	.loc 3 54 5
	mul.ftz.f32 	%f38, %f37, 0f43800000;
	cvt.rzi.ftz.u32.f32	%r11, %f38;
	.loc 5 868 10
	min.u32 	%r12, %r11, %r7;
	.loc 3 61 91
	mul.wide.u32 	%rd4, %r5, 4;
	add.s64 	%rd5, %rd3, %rd4;
	.loc 5 868 10
	cvt.u16.u32	%rs1, %r12;
	.loc 5 868 10
	cvt.u16.u32	%rs2, %r10;
	.loc 5 868 10
	cvt.u16.u32	%rs3, %r8;
	mov.u16 	%rs4, 255;
	.loc 3 61 91
	st.global.v4.u8 	[%rd5], {%rs3, %rs2, %rs1, %rs4};
	.loc 1 45 1
	ret;
}

	.file	1 "C:/Users/kmorley/Code/optix_sdk/samples_exp/optixHello/draw_solid_color.cu", 1584979538, 2040
	.file	2 "C:\\Users\\kmorley\\Code\\optix_sdk\\include\\internal/optix_7_device_impl.h", 1601908730, 95893
	.file	3 "C:/Users/kmorley/Code/optix_sdk/samples_exp\\cuda/helpers.h", 1584979493, 2977
	.file	4 "C:/Users/kmorley/Code/optix_sdk/samples_exp\\sutil/vec_math.h", 1584979542, 76205
	.file	5 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v11.0\\include\\crt\\math_functions.hpp", 1588841123, 96062
'''

import optix
import cupy

class Logger:
    def __call__( self, level, tag, mssg ):
        print( "[{:>2}][{:>12}]: {}".format( level, tag, mssg ) )

def log_callback( level, tag, mssg ):
    print( "[{:>2}][{:>12}]: {}".format( level, tag, mssg ) )


def init_optix():
    print( "Initializing cuda ..." )
    cupy.cuda.runtime.free( 0 )

    print( "Initializing optix ..." )
    optix.init()


def create_ctx():
    print( "Creating optix device context ..." )
    cu_ctx      = optix.cuda.Context()
    ctx_options = optix.DeviceContextOptions()
    #dco.logCallbackFunction = log_callback 

    logger = Logger()
    ctx_options.logCallbackFunction = logger
    ctx_options.logCallbackLevel    = 4

    return optix.deviceContextCreate( cu_ctx, ctx_options )


def create_module( ctx, pipeline_options ):

    print( "Creating optix module ..." )

    module_options = optix.ModuleCompileOptions()
    module_options.maxRegisterCount = 0 # need to wrap #defines (eg, optix.COMPILE_DEFAULT_MAX_REGISTER_COUNT )
    module_options.optLevel         = optix.COMPILE_OPTIMIZATION_DEFAULT
    module_options.debugLevel       = optix.COMPILE_DEBUG_LEVEL_LINEINFO

    log = ""
    return ctx.moduleCreateFromPTX(
            module_options,
            pipeline_options,
            draw_color_ptx,
            log
            )
    print( "\t{}".format( log ) )


init_optix()
ctx = create_ctx()

pipeline_options = optix.PipelineCompileOptions()
pipeline_options.usesMotionBlur        = False;
pipeline_options.traversableGraphFlags = optix.TRAVERSABLE_GRAPH_FLAG_ALLOW_SINGLE_LEVEL_INSTANCING;
pipeline_options.numPayloadValues      = 2;
pipeline_options.numAttributeValues    = 2;
pipeline_options.exceptionFlags        = optix.EXCEPTION_FLAG_NONE;
pipeline_options.pipelineLaunchParamsVariableName = "params";

module = create_module( ctx, pipeline_options )


print( "Creating program groups ... " )



