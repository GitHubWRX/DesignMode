class ITarget
{
private:
    /* data */
public:
    ITarget(/* args */);
    virtual void process()=0;
    ~ITarget();
};

ITarget::ITarget(/* args */)
{
}

ITarget::~ITarget()
{
}
