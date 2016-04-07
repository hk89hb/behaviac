/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H
#define BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H

#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

namespace behaviac
{
    /*! \addtogroup treeNodes Behavior Tree
    * @{
    * \addtogroup DecoratorLog
    * @{ */

    /**
    Output message specified when it updates.
    */
    class BEHAVIAC_API DecoratorLog : public DecoratorNode
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLog, DecoratorNode);

        DecoratorLog();
        virtual ~DecoratorLog();
        virtual void load(int version, const char* agentType, const properties_t& properties);

    protected:
        virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

    private:
        virtual BehaviorTask* createTask() const;

    protected:
        behaviac::string m_message;

        friend class DecoratorLogTask;
    };

    class BEHAVIAC_API DecoratorLogTask : public DecoratorTask
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLogTask, DecoratorTask);

        DecoratorLogTask() : DecoratorTask()
        {
        }

    protected:
        virtual void copyto(BehaviorTask* target) const;
        virtual void save(ISerializableNode* node) const;
        virtual void load(ISerializableNode* node);

        virtual EBTStatus decorate(EBTStatus status);
    };
    /*! @} */
    /*! @} */
}

#endif//BEHAVIAC_BEHAVIORTREE_DECORATORLOG_H