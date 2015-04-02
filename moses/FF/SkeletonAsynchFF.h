#pragma once

#include <string>
#include "moses/HypothesisStackNormal.h"
#include "moses/TrellisPathList.h"
#include "AsynchFeatureFunction.h"

namespace Moses
{

class SkeletonAsynchFF : public AsynchFeatureFunction
{
public:
  SkeletonAsynchFF(const std::string &line);

  bool IsUseable(const FactorMask &mask) const {
    return true;
  }

   /*
    *  Evaluate functions for Asynch features
    */

  void EvaluateNbest(const InputType &input,
	                     const TrellisPathList &Nbest) const;

  void EvaluateSearchGraph(const InputType &input,
		  	   const std::vector < HypothesisStack* > &hypoStackColl ) const;

  /**
   *
   */

  void EvaluateInIsolation(const Phrase &source
                           , const TargetPhrase &targetPhrase
                           , ScoreComponentCollection &scoreBreakdown
                           , ScoreComponentCollection &estimatedFutureScore) const;
  void EvaluateWithSourceContext(const InputType &input
                                 , const InputPath &inputPath
                                 , const TargetPhrase &targetPhrase
                                 , const StackVec *stackVec
                                 , ScoreComponentCollection &scoreBreakdown
                                 , ScoreComponentCollection *estimatedFutureScore = NULL) const;

  void EvaluateTranslationOptionListWithSourceContext(const InputType &input
      , const TranslationOptionList &translationOptionList) const;

  void EvaluateWhenApplied(const Hypothesis& hypo,
                           ScoreComponentCollection* accumulator) const;
  void EvaluateWhenApplied(const ChartHypothesis &hypo,
                           ScoreComponentCollection* accumulator) const;


  void SetParameter(const std::string& key, const std::string& value);

};

}

