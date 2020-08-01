//ln -s XXX.cpp XXX.cu
//Cu008_cuda.cc
//Cu007 850bab723fb5687435d280831aa00687
//Cu16 Piza_cuda.cpp
//Cu15 Piza_cuda.cpp
//Cu14 Piza_cuda.cpp
//Cu13 Piza_cuda.cpp
//Cu12 cpp cu combo test.cpp
//nvcc Main.cpp Sub.cu
//
       #include <unistd.h>
       #include <iostream>
       #include <stdio.h>

int main(int argc,char **argv){
    int cpu_mem = 774;
    int *cuda_mem;
    int N=sizeof(int);
    

//cudaSuccess, cudaErrorInvalidValue, cudaErrorMemoryAllocation
std::cout <<"CUDA OK"<<std::endl;
    cudaMalloc(&cuda_mem,N);//access mergin 2.2
    cudaMemcpy (cuda_mem,&cpu_mem,N,cudaMemcpyHostToDevice);
    std::cout <<"num ="<<cpu_mem<<std::flush;


    cudaDeviceSynchronize();
    
    cuda_kernel<<<1,1>>>(cuda_mem);

    cudaDeviceSynchronize();
    cudaMemcpy (&cpu_mem,cuda_mem,N,cudaMemcpyHostToDevice);
    cudaDeviceSynchronize();


    
    return (int)false;
}