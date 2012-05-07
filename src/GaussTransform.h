#ifndef IMAGESTACK_GAUSS_TRANSFORM_H
#define IMAGESTACK_GAUSS_TRANSFORM_H
#include "header.h"


class GaussTransform : public Operation {
public:
    enum Method {AUTO = 0, EXACT, GRID, SPARSEGRID, PERMUTOHEDRAL, GKDTREE};

    void help();
    void parse(vector<string> args);
    static NewImage apply(NewImage slicePositions, NewImage splatPositions, NewImage values,
                       vector<float> sigmas, Method m = AUTO);
};


class JointBilateral : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(NewImage image, NewImage reference,
                      float filterWidth, float filterHeight, float filterFrames, float colorSigma,
                      GaussTransform::Method m = GaussTransform::AUTO);
};

class Bilateral : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(NewImage image, float filterWidth, float filterHeight,
                      float filterFrames, float colorSigma,
                      GaussTransform::Method m = GaussTransform::AUTO);
};


class BilateralSharpen : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static NewImage apply(NewImage im, float spatialSigma, float colorSigma, float sharpness);
};

class ChromaBlur : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static NewImage apply(NewImage im, float spatialSigma, float colorSigma);
};



class NLMeans : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(NewImage image, float patchSize, int dimensions,
                      float spatialSigma, float patchSigma,
                      GaussTransform::Method m = GaussTransform::AUTO);
};

class NLMeans3D : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(NewImage image, float patchSize, int dimensions,
                      float spatialSigma, float patchSigma,
                      GaussTransform::Method m = GaussTransform::AUTO);
};

#include "footer.h"
#endif
